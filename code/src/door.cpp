#include"door.hpp"

//NOT_DOOR
NOT_DOOR::NOT_DOOR() {
	this->name = "NOT_GATE";
}
NOT_DOOR::~NOT_DOOR() {
	this->input.clear();
	this->output.clear();
}
void NOT_DOOR::setlabel(int _lab) {
	this->label = _lab;
}
int NOT_DOOR::getlabel() {
	return this->label;
}
bool NOT_DOOR::setinput(DOOR* other) {
	if (!(this->input.empty()))return false;
	else {
		this->input.push_back(other);
		return true;
	}
}
bool NOT_DOOR::setoutput(DOOR* other) {
	this->output.push_back(other);
	return true;
}
DOOR* NOT_DOOR::getinput(int i) {
	try {
		return this->input.at(i);
	}
	catch (const std::out_of_range& oor) {
		std::cerr << "Out of Range error: " << oor.what() << '\n';
	}
}
DOOR* NOT_DOOR::getoutput(int i) {
	try {
		return this->output.at(i);
	}
	catch (const std::out_of_range& oor) {
		std::cerr << "Out of Range error: " << oor.what() << '\n';
	}
}

//AND_DOOR
AND_DOOR::AND_DOOR() {
	this->name = "AND_GATE";
}
AND_DOOR::~AND_DOOR() {

}
bool AND_DOOR::setinput(DOOR* other) {
	this->input.push_back(other);
	return true;
}
bool AND_DOOR::setoutput(DOOR* other) {
	this->output.push_back(other);
	return true;
}
DOOR* AND_DOOR::getinput(int i) {
	try {
		return this->input.at(i);
	}
	catch (const std::out_of_range& oor) {
		std::cerr << "Out of Range error: " << oor.what() << '\n';
	}
}
DOOR* AND_DOOR::getoutput(int i) {
	try {
		return this->output.at(i);
	}
	catch (const std::out_of_range& oor) {
		std::cerr << "Out of Range error: " << oor.what() << '\n';
	}
}
void AND_DOOR::setlabel(int _lab) {
	this->label = _lab;
}
int AND_DOOR::getlabel() {
	return this->label;
}

//OR_DOOR
OR_DOOR::OR_DOOR(){
	this->name = "OR_GATE";
}
OR_DOOR::~OR_DOOR() {

}
bool OR_DOOR::setinput(DOOR* other) {
	this->input.push_back(other);
	return true;
}
bool OR_DOOR::setoutput(DOOR* other) {
	this->output.push_back(other);
	return true;
}
DOOR* OR_DOOR::getinput(int i) {
	try {
		return this->input.at(i);
	}
	catch (const std::out_of_range& oor) {
		std::cerr << "Out of Range error: " << oor.what() << '\n';
	}
}
DOOR* OR_DOOR::getoutput(int i) {
	try {
		return this->output.at(i);
	}
	catch (const std::out_of_range& oor) {
		std::cerr << "Out of Range error: " << oor.what() << '\n';
	}
}
void OR_DOOR::setlabel(int _lab) {
	this->label = _lab;
}
int OR_DOOR::getlabel() {
	return this->label;
}

//XOR_DOOR
XOR_DOOR::XOR_DOOR() {
	this->name = "XOR_GATE";
}
XOR_DOOR::~XOR_DOOR() {

}
bool XOR_DOOR::setinput(DOOR* other) {
	this->input.push_back(other);
	return true;
}
bool XOR_DOOR::setoutput(DOOR* other) {
	this->output.push_back(other);
	return true;
}
DOOR* XOR_DOOR::getinput(int i) {
	try {
		return this->input.at(i);
	}
	catch (const std::out_of_range& oor) {
		std::cerr << "Out of Range error: " << oor.what() << '\n';
	}
}
DOOR* XOR_DOOR::getoutput(int i) {
	try {
		return this->output.at(i);
	}
	catch (const std::out_of_range& oor) {
		std::cerr << "Out of Range error: " << oor.what() << '\n';
	}
}
void XOR_DOOR::setlabel(int _lab) {
	this->label = _lab;
}
int XOR_DOOR::getlabel() {
	return this->label;
}


NAND_DOOR::NAND_DOOR() {
	this->name = "NAND_GATE";
}
NAND_DOOR::~NAND_DOOR() {

}
bool NAND_DOOR::setinput(DOOR* other) {
	this->input.push_back(other);
	return true;
}

bool NAND_DOOR::setoutput(DOOR* other) {
	this->output.push_back(other);
	return true;
}
DOOR* NAND_DOOR::getinput(int i) {
	try {
		return this->input.at(i);
	}
	catch (const std::out_of_range& oor) {
		std::cerr << "Out of Range error: " << oor.what() << '\n';
	}
}
DOOR* NAND_DOOR::getoutput(int i) {
	try {
		return this->output.at(i);
	}
	catch (const std::out_of_range& oor) {
		std::cerr << "Out of Range error: " << oor.what() << '\n';
	}
}
void NAND_DOOR::setlabel(int _lab) {
	this->label = _lab;
}
int NAND_DOOR::getlabel() {
	return this->label;
}

//GROUND_DOOR
GROUND_DOOR::GROUND_DOOR() {
	this->electricity = false;
	this->label = -1;
	this->name = "GROUND";
}
DOOR* GROUND_DOOR::getoutput(int i) {
	try {
		return this->output.at(i);
	}
	catch (const std::out_of_range& oor) {
		std::cerr << "Out of Range error: " << oor.what() << '\n';
	}
}
bool GROUND_DOOR::setoutput(DOOR* other) {
	this->output.push_back(other);
	return true;
}
GROUND_DOOR::~GROUND_DOOR(){
	
}

//VCC
VCC::VCC() {
	this->electricity = true;
	this->label = -2;
	this->name = "VCC";
}
VCC::~VCC() {

}
DOOR* VCC::getoutput(int i) {
	try {
		return this->output.at(i);
	}
	catch (const std::out_of_range& oor) {
		std::cerr << "Out of Range error: " << oor.what() << '\n';
	}
}
bool VCC::setoutput(DOOR* other) {
	this->output.push_back(other);
	return true;
}


