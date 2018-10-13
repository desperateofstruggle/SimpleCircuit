#include"Door_List.hpp"
#include<map>
#include<stack>
std::map<int, bool>marked;//���Ա���Ƿ��������ýڵ�
std::map<int, bool>onStack;//���Լ�¼�Ƿ��ѵ����ýڵ�
std::map<int, DOOR*>edgeTO;//��¼����ĳһ�ڵ����һ�ڵ�
std::stack<DOOR*>cycle;//��¼���Դ�ӡ

//����(��) 
void dfs(DOOR* node) {
	if (!cycle.empty())return;
	if (node->get_inside_vector_size() == 0)return;
	marked[node->getlabel()] = true;
	onStack[node->getlabel()] = true;
	for (int i = 0; i < node->get_inside_vector_size(); i++) {
		DOOR* temp = node->getinput(i);
		if (!marked[temp->getlabel()]) {
			edgeTO[temp->getlabel()] = node;
			dfs(temp);
		}
		else if (onStack[temp->getlabel()]) {
			edgeTO[temp->getlabel()] = node;
			//Ū��һ����
			DOOR* f = node;
			cycle.push(f);
			f = edgeTO[f->getlabel()];
			while (f != node) {
				cycle.push(f);
				f = edgeTO[f->getlabel()];
			}
			cycle.push(f);
			return;
		}
	}
	onStack[node->getlabel()] = false;
}
//����(����)
void dfs1(DOOR* node) {
	if (marked[node->getlabel()])return;
	marked[node->getlabel()] = true;
	for (int i = 0; i < node->get_inside_vector_size(); i++) {
		dfs1(node->getinput(i));
	}
	node->excute();
}
//����(�����ж��Ƿ������������)
void DOOR_LIST::excuting() {
	for (int i = 0; i < this->LOGIC_DOOR.size(); i++) {
		marked.insert(std::map<int, bool>::value_type(this->LOGIC_DOOR[i]->getlabel(), false));
	}
	for (int j = 0; j < OUT_PRINT.size(); j++) {
		dfs1(OUT_PRINT[j]);
	}
	marked.clear();
}
//��黷
bool is_cycle(std::vector<DOOR*>&sam) {
	//ȫ��map���ݳ�ʼ��
	for (int i = 0; i < sam.size(); i++) {
		marked.insert(std::map<int, bool>::value_type(sam[i]->getlabel(), false));
		onStack.insert(std::map<int, bool>::value_type(sam[i]->getlabel(), false));
		edgeTO.insert(std::map<int, DOOR*>::value_type(sam[i]->getlabel(), NULL));
	}
	//��ʼ��黷
	for (int i = 0; i < sam.size(); i++) {
		if (!cycle.empty()) {
			//����������ջ�뼸����
			int cycle_size = cycle.size();
			std::cout << "���ڻ��� ";
			for (int num=0; num < cycle_size; num++) {
				DOOR* p1 = cycle.top();
				if(num!=cycle_size-1)std::cout << p1->getlabel() << " -> " ;
				else std::cout << p1->getlabel() << std::endl;
				cycle.pop();
			}
			marked.clear();
			onStack.clear();
			edgeTO.clear();
			return true;
		}
		else{
			dfs(sam[i]);
		}
	}
	if (!cycle.empty()) {
		//����������ջ�뼸����
		int cycle_size = cycle.size();
		std::cout << "���ڻ��� ";
		for (int num = 0; num < cycle_size; num++) {
			DOOR* p1 = cycle.top();
			if (num != cycle_size - 1)std::cout << p1->getlabel() << " -> ";
			else std::cout << p1->getlabel() << std::endl;
			cycle.pop();
		}
		marked.clear();
		onStack.clear();
		edgeTO.clear();
		return true;
	}
	marked.clear();
	onStack.clear();
	edgeTO.clear();
	return false;
}

DOOR_LIST::DOOR_LIST() {
	DOOR* GUD = new GROUND_DOOR();
	DOOR* vcc = new VCC();
	this->LOGIC_DOOR.push_back(GUD);
	this->LOGIC_DOOR.push_back(vcc);
}
DOOR_LIST::~DOOR_LIST() {
	
}
void DOOR_LIST::remove_all() {
	int numb = this->LOGIC_DOOR.size();
	for (int i = 0; i < numb; i++) {
		delete this->LOGIC_DOOR[i];
	}
}

//������Ͽ�
bool DOOR_LIST::connect(DOOR* a,DOOR* b) {
	if (!(b->setinput(a)))return false;
	if (!(a->setoutput(b)))return false;
	return true;
}
bool DOOR_LIST::cut(DOOR* a,int a_label, DOOR* b,int b_label) {
	a->removeoutput(b_label);
	b->removeinput(a_label);
	return  true;
}

//��������ź��������
void DOOR_LIST::add_door(DOOR* other) {
	this->LOGIC_DOOR.push_back(other);
}
void DOOR_LIST::add_outdoor(DOOR* other) {
	this->OUT_PRINT.push_back(other);
}

//�Ѵ������ɾ��
bool DOOR_LIST :: remove_door(int _label) {
	for (std::vector<DOOR*>::iterator it = LOGIC_DOOR.begin(); it != LOGIC_DOOR.end(); it++) {
		if ((*it)->getlabel() != _label)continue;
		else {
			for (std::vector<DOOR*>::iterator its = OUT_PRINT.begin(); its != OUT_PRINT.end(); its++) {
				if((*it)->getlabel()==(*its)->getlabel())
					this->OUT_PRINT.erase(its);
			}
			delete *it;
			this->LOGIC_DOOR.erase(it);
			return true;
		}
	}
	return false;
}
//�ж��Ƿ���������
bool DOOR_LIST::is_here_door(int _label) {
	for (std::vector<DOOR*>::iterator it = LOGIC_DOOR.begin(); it != LOGIC_DOOR.end(); it++) {
		if ((*it)->getlabel() != _label)continue;
		else {
			return true;
		}
	}
	return false;
}
//�����ŵı������
DOOR* DOOR_LIST::find_door(int _label) {
	if (!is_here_door(_label))return NULL;
	else {
		int num = 0;
		for (std::vector<DOOR*>::iterator it = LOGIC_DOOR.begin(); it != LOGIC_DOOR.end(); it++) {
			if ((*it)->getlabel() != _label) {
				num++;
				continue;
			}
			else {
				return this->LOGIC_DOOR[num];
			}
			num++;
		}
	}

}

//����Ĳ黷�����ӿ�(true-�л� false-�޻�)
bool DOOR_LIST::check_graph() {
	return is_cycle(this->LOGIC_DOOR);
}
//����ļ���Ƿ�������������Ľӿ�(true-���� false-������)
bool DOOR_LIST::check_excute() {
	for (int i = 0; i < this->LOGIC_DOOR.size(); i++) {
		if (!this->LOGIC_DOOR[i]->is_exc_correct())
			return false;
	}
	return true;
}
//��������ݸ�ʽ����ӡ��·�����ӿ�
void DOOR_LIST::read() {
	if (this->LOGIC_DOOR.size() == 0)std::cout << "Now there is no gate created." << std::endl;
	else {
		for (int i = 0; i < this->LOGIC_DOOR.size(); i++) {
			if (this->LOGIC_DOOR[i]->get_inside_vector_size() == 0)std::cout << this->LOGIC_DOOR[i]->getlabel() << " ( " << this->LOGIC_DOOR[i]->get_name() << " ) <- NULL"<<std::endl;
			else {
				for (int j = 0; j < this->LOGIC_DOOR[i]->get_inside_vector_size();j++) {
					std::cout << this->LOGIC_DOOR[i]->getlabel() << " ( "<<this->LOGIC_DOOR[i]->get_name()<<" ) <- " << this->LOGIC_DOOR[i]->getinput(j)->getlabel()<<" ( "<<this->LOGIC_DOOR[i]->getinput(j)->get_name()<<" )"<<std::endl;
				}
			}
		}
	}
}
