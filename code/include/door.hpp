#ifndef DOOR_HPP
#define DOOR_HPP
#include<vector>
#include<iostream>
#include<string>
class DOOR {
public:
	virtual ~DOOR(){}
	virtual bool setinput(DOOR*)=0;
	virtual bool setoutput(DOOR*)=0;
	virtual DOOR* getinput(int)=0;
	virtual DOOR* getoutput(int)=0;
	virtual void removeinput(int) = 0;
	virtual void removeoutput(int) = 0;

	virtual void setlabel(int) = 0; 
	virtual int getlabel() = 0; 

	virtual bool getelectricity() = 0;
	virtual void setelectricity(bool) = 0;

	virtual int get_inside_vector_size() = 0;
	virtual int get_outside_vector_size() = 0;

	virtual void excute() = 0;
	virtual bool is_exc_correct()=0;
	virtual std::string get_name() = 0;
private:
	/*std::vector<DOOR*>input;
	std::vector<DOOR*>output;
	bool electricity;
	int label;*/

};

//输入端
class INPUT_DOOR :public DOOR {
public:
	INPUT_DOOR(){
		this->name = "INPUT_GATE";
	}
	~INPUT_DOOR(){}
	bool setinput(DOOR* p) { return true; }
	bool setoutput(DOOR* other) {
		this->output.push_back(other);
		return true;
	}
	DOOR* getinput(int) { return NULL; }
	DOOR* getoutput(int i) {
		try {
			return this->output.at(i);
		}
		catch (const std::out_of_range& oor) {
			std::cerr << "Out of Range error: " << oor.what() << '\n';
		}
	}
	void removeinput(int) {}
	void removeoutput(int _label) {
		for (std::vector<DOOR*>::iterator it = output.begin(); it != output.end(); it++) {
			if ((*it)->getlabel() != _label)continue;
			else {
				this->output.erase(it);
				return;
			}
		}
	}
	void setlabel(int _lab = -1) { this->label = _lab; }
	int getlabel() { return this->label; }

	bool getelectricity() { return this->electricity; }
	void setelectricity(bool x) { this->electricity = x; }

	int get_inside_vector_size() { return 0; }
	int get_outside_vector_size() { return this->output.size(); }

	void excute() {}
	bool is_exc_correct() {
		if (this->get_inside_vector_size() == 0)return true;
		else return false;
	}
	std::string get_name() { return this->name; }
private:
	std::vector<DOOR*>output;
	bool electricity;
	int label;
	std::string name;

};

//输出端
class OUTPUT_DOOR :public DOOR {
public:
	OUTPUT_DOOR(){
		this->name = "OUTPUT_GATE";
	}
	~OUTPUT_DOOR(){}
	bool setinput(DOOR* other) { 
		if (!(this->input.empty()))return false;
		else {
			this->input.push_back(other);
			return true;
		}
	}
	bool setoutput(DOOR* other) {
		return true;
	}
	DOOR* getinput(int i) { 
		try {
			return this->input.at(i);
		}
		catch (const std::out_of_range& oor) {
			std::cerr << "Out of Range error: " << oor.what() << '\n';
		}
	}
	DOOR* getoutput(int i) { return NULL; }
	void removeinput(int _label) {
		for (std::vector<DOOR*>::iterator it = input.begin(); it != input.end(); it++) {
			if ((*it)->getlabel() != _label)continue;
			else {
				this->input.erase(it);
				return;
			}
		}
	}
	void removeoutput(int _label) {}
	void setlabel(int _lab = -1) { this->label = _lab; }
	int getlabel() { return this->label; }

	bool getelectricity() { return this->electricity; }
	void setelectricity(bool x) { this->electricity = x; }

	int get_inside_vector_size() { return this->input.size(); }
	int get_outside_vector_size() { return 0; }
	void excute() {
		if (!input.empty())this->electricity = input[0]->getelectricity();
		else return;
	}
	bool is_exc_correct() {
		if (this->get_inside_vector_size() != 1)return false;
		else return true;
	}
	std::string get_name() { return this->name; }
private:
	std::vector<DOOR*>input;
	bool electricity;
	int label;
	std::string name;
};

//里面的label没啥用
class GROUND_DOOR :public DOOR {
public:
	GROUND_DOOR();
	~GROUND_DOOR();
	bool setinput(DOOR* p) { return true; }
	bool setoutput(DOOR* other);
	DOOR* getinput(int) {return NULL;}
	DOOR* getoutput(int i);
	void removeinput(int){}
	void removeoutput(int _label) {
		for (std::vector<DOOR*>::iterator it = output.begin(); it != output.end(); it++) {
			if ((*it)->getlabel() != _label)continue;
			else {
				this->output.erase(it);
				return;
			}
		}
	}
	void setlabel(int _lab=-1) { this->label = _lab; }
	int getlabel() { return this->label; }

	bool getelectricity() { return this->electricity; }
	void setelectricity(bool x) { this->electricity = false; }
	
	int get_inside_vector_size() { return 0; }
	int get_outside_vector_size() { return this->output.size(); }
	void excute() {}
	bool is_exc_correct() {
		if (this->get_inside_vector_size() > 0)return false;
		else return true;
	}
	std::string get_name() { return this->name; }
private:
	//std::vector<DOOR*>input;
	std::vector<DOOR*>output;
	bool electricity;
	int label;
	std::string name;
};

class VCC :public DOOR{
public:
	VCC();
	~VCC();
	bool setinput(DOOR* p) { return true; }
	bool setoutput(DOOR* other);
	DOOR* getinput(int) { return NULL; }
	DOOR* getoutput(int i);
	void removeinput(int) {}
	void removeoutput(int _label) {
		for (std::vector<DOOR*>::iterator it = output.begin(); it != output.end(); it++) {
			if ((*it)->getlabel() != _label)continue;
			else {
				this->output.erase(it);
				return;
			}
		}
	}
	void setlabel(int _lab=-2) { this->label = _lab; }
	int getlabel() { return this->label; }
	bool getelectricity() { return this->electricity; }
	void setelectricity(bool x) { this->electricity = true; }

	int get_inside_vector_size() { return 0; }
	int get_outside_vector_size() { return this->output.size(); }
	void excute() {}
	bool is_exc_correct() {
		if (this->get_inside_vector_size() > 0)return false;
		else return true;
	}
	std::string get_name() { return this->name; }
private:
	//std::vector<DOOR*>input;
	std::vector<DOOR*>output;
	bool electricity;
	int label;
	std::string name;
};

class NOT_DOOR :public DOOR {
public:
	NOT_DOOR();
	~NOT_DOOR();
	bool setinput(DOOR*);
	bool setoutput(DOOR*);
	DOOR* getinput(int);
	DOOR* getoutput(int);
	void removeinput(int _label) {
		for (std::vector<DOOR*>::iterator it = input.begin(); it != input.end(); it++) {
			if ((*it)->getlabel() != _label)continue;
			else {
				this->input.erase(it);
				return;
			}
		}
	}
	void removeoutput(int _label) {
		for (std::vector<DOOR*>::iterator it = output.begin(); it != output.end(); it++) {
			if ((*it)->getlabel() != _label)continue;
			else {
				this->output.erase(it);
				return;
			}
		}
	}
	void setlabel(int);
	int getlabel();
	bool getelectricity() {return this->electricity;}
	void setelectricity(bool x) {this->electricity = x;}
	int get_inside_vector_size() { return this->input.size(); }
	int get_outside_vector_size() { return this->output.size(); }
	void excute() {
		if (!this->input.empty())this->electricity = !(this->input[0]->getelectricity());
		else return;
	}
	bool is_exc_correct() {
		if (this->get_inside_vector_size()!=1)return false;
		else return true;
	}
	std::string get_name() { return this->name; }
private:
	std::vector<DOOR*>input;
	std::vector<DOOR*>output;
	bool electricity;
	int label;
	std::string name;

};

class AND_DOOR :public DOOR {
public:
	AND_DOOR();
	~AND_DOOR();
	bool setinput(DOOR*);
	bool setoutput(DOOR*);
	DOOR* getinput(int);
	DOOR* getoutput(int);
	void removeinput(int _label) {
		for (std::vector<DOOR*>::iterator it = input.begin(); it != input.end(); it++) {
			if ((*it)->getlabel() != _label)continue;
			else {
				this->input.erase(it);
				return;
			}
		}
	}
	void removeoutput(int _label) {
		for (std::vector<DOOR*>::iterator it = output.begin(); it != output.end(); it++) {
			if ((*it)->getlabel() != _label)continue;
			else {
				this->output.erase(it);
				return;
			}
		}
	}
	
	void setlabel(int);
	int getlabel();
	bool getelectricity() {return this->electricity;}
	void setelectricity(bool x) {this->electricity = x;}
	int get_inside_vector_size() { return this->input.size(); }
	int get_outside_vector_size() { return this->output.size(); }
	void excute() {
		if (this->get_inside_vector_size()>=2) {
			this->electricity = this->input[0]->getelectricity();
			for (int i = 1; i < this->get_inside_vector_size(); i++) {
				this->electricity = this->input[i]->getelectricity() && this->electricity;
			}
		}
		else return;
	}
	bool is_exc_correct() {
		if (this->get_inside_vector_size()<2)return false;
		else return true;
	}
	std::string get_name() { return this->name; }

private:
	std::vector<DOOR*>input;
	std::vector<DOOR*>output;
	bool electricity;
	int label;
	std::string name;
};


class OR_DOOR :public DOOR {
public:
	OR_DOOR();
	~OR_DOOR();
	bool setinput(DOOR*);
	bool setoutput(DOOR*);
	DOOR* getinput(int);
	DOOR* getoutput(int);
	void removeinput(int _label) {
		for (std::vector<DOOR*>::iterator it = input.begin(); it != input.end(); it++) {
			if ((*it)->getlabel() != _label)continue;
			else {
				this->input.erase(it);
				return;
			}
		}
	}
	void removeoutput(int _label) {
		for (std::vector<DOOR*>::iterator it = output.begin(); it != output.end(); it++) {
			if ((*it)->getlabel() != _label)continue;
			else {
				this->output.erase(it);
				return;
			}
		}
	}
	void setlabel(int);
	int getlabel();
	bool getelectricity() { return this->electricity; }
	void setelectricity(bool x) { this->electricity = x; }
	int get_inside_vector_size() { return this->input.size(); }
	int get_outside_vector_size() { return this->output.size(); }

	void excute() {
		if (this->get_inside_vector_size() >= 2) {
			this->electricity = this->input[0]->getelectricity();
			for (int i = 1; i < this->get_inside_vector_size(); i++) {
				this->electricity = this->input[i]->getelectricity() || this->electricity;
			}
		}
		else return;
	}
	bool is_exc_correct() {
		if (this->get_inside_vector_size()<2)return false;
		else return true;
	}
	std::string get_name() { return this->name; }

private:
	std::vector<DOOR*>input;
	std::vector<DOOR*>output;
	bool electricity;
	int label;
	std::string name;
};

class XOR_DOOR :public DOOR {
public:
	XOR_DOOR();
	~XOR_DOOR();
	bool setinput(DOOR*);
	bool setoutput(DOOR*);
	DOOR* getinput(int);
	DOOR* getoutput(int);
	void removeinput(int _label) {
		for (std::vector<DOOR*>::iterator it = input.begin(); it != input.end(); it++) {
			if ((*it)->getlabel() != _label)continue;
			else {
				this->input.erase(it);
				return;
			}
		}
	}
	void removeoutput(int _label) {
		for (std::vector<DOOR*>::iterator it = output.begin(); it != output.end(); it++) {
			if ((*it)->getlabel() != _label)continue;
			else {
				this->output.erase(it);
				return;
			}
		}
	}
	void setlabel(int);
	int getlabel();
	bool getelectricity() { return this->electricity; }
	void setelectricity(bool x) { this->electricity = x; }
	int get_inside_vector_size() { return this->input.size(); }
	int get_outside_vector_size() { return this->output.size(); }
	void excute() {
		if (this->get_inside_vector_size() >= 2) {
			this->electricity = this->input[0]->getelectricity();
			for (int i = 1; i < this->get_inside_vector_size(); i++) {
				if (this->electricity != this->input[i]->getelectricity()) {
					this->electricity = true;
				}
				else {
					this->electricity = false;
				}
			}
		}
		else return;
	}
	bool is_exc_correct() {
		if (this->get_inside_vector_size()<2)return false;
		else return true;
	}
	std::string get_name() { return this->name; }

private:
	std::vector<DOOR*>input;
	std::vector<DOOR*>output;
	bool electricity;
	int label;
	std::string name;
};

class NAND_DOOR :public DOOR {
public:
	NAND_DOOR();
	~NAND_DOOR();
	bool setinput(DOOR*);
	bool setoutput(DOOR*);
	DOOR* getinput(int);
	DOOR* getoutput(int);
	void removeinput(int _label) {
		for (std::vector<DOOR*>::iterator it = input.begin(); it != input.end(); it++) {
			if ((*it)->getlabel() != _label)continue;
			else {
				this->input.erase(it);
				return;
			}
		}
	}
	void removeoutput(int _label) {
		for (std::vector<DOOR*>::iterator it = output.begin(); it != output.end(); it++) {
			if ((*it)->getlabel() != _label)continue;
			else {
				this->output.erase(it);
				return;
			}
		}
	}
	void setlabel(int);
	int getlabel();
	bool getelectricity() { return this->electricity; }
	void setelectricity(bool x) { this->electricity = x; }
	int get_inside_vector_size() { return this->input.size(); }
	int get_outside_vector_size() { return this->output.size(); }
	void excute() {
		if (this->get_inside_vector_size() >= 2) {
			this->electricity = this->input[0]->getelectricity();
			for (int i = 1; i < this->get_inside_vector_size(); i++) {
				this->electricity = this->input[i]->getelectricity() && this->electricity;
			}
			this->electricity = !this->electricity;
		}
		else return;
	}
	bool is_exc_correct() {
		if (this->get_inside_vector_size()<2)return false;
		else return true;
	}
	std::string get_name() { return this->name; }
private:
	std::vector<DOOR*>input;
	std::vector<DOOR*>output;
	bool electricity;
	int label;
	std::string name;
};

#endif // !DOOR_HPP

