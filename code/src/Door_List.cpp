#include"Door_List.hpp"
#include<map>
#include<stack>
std::map<int, bool>marked;//用以标记是否搜索过该节点
std::map<int, bool>onStack;//用以记录是否已弹出该节点
std::map<int, DOOR*>edgeTO;//记录到达某一节点的上一节点
std::stack<DOOR*>cycle;//记录环以打印

//深搜(环) 
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
			//弄成一个环
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
//深搜(计算)
void dfs1(DOOR* node) {
	if (marked[node->getlabel()])return;
	marked[node->getlabel()] = true;
	for (int i = 0; i < node->get_inside_vector_size(); i++) {
		dfs1(node->getinput(i));
	}
	node->excute();
}
//运行(不含判断是否符合运行条件)
void DOOR_LIST::excuting() {
	for (int i = 0; i < this->LOGIC_DOOR.size(); i++) {
		marked.insert(std::map<int, bool>::value_type(this->LOGIC_DOOR[i]->getlabel(), false));
	}
	for (int j = 0; j < OUT_PRINT.size(); j++) {
		dfs1(OUT_PRINT[j]);
	}
	marked.clear();
}
//检查环
bool is_cycle(std::vector<DOOR*>&sam) {
	//全局map数据初始化
	for (int i = 0; i < sam.size(); i++) {
		marked.insert(std::map<int, bool>::value_type(sam[i]->getlabel(), false));
		onStack.insert(std::map<int, bool>::value_type(sam[i]->getlabel(), false));
		edgeTO.insert(std::map<int, DOOR*>::value_type(sam[i]->getlabel(), NULL));
	}
	//开始检查环
	for (int i = 0; i < sam.size(); i++) {
		if (!cycle.empty()) {
			//检测完后清零栈与几个数
			int cycle_size = cycle.size();
			std::cout << "存在环： ";
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
		//检测完后清零栈与几个数
		int cycle_size = cycle.size();
		std::cout << "存在环： ";
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

//连接与断开
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

//添加所有门和输出的门
void DOOR_LIST::add_door(DOOR* other) {
	this->LOGIC_DOOR.push_back(other);
}
void DOOR_LIST::add_outdoor(DOOR* other) {
	this->OUT_PRINT.push_back(other);
}

//把创造的门删除
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
//判断是否存在这个门
bool DOOR_LIST::is_here_door(int _label) {
	for (std::vector<DOOR*>::iterator it = LOGIC_DOOR.begin(); it != LOGIC_DOOR.end(); it++) {
		if ((*it)->getlabel() != _label)continue;
		else {
			return true;
		}
	}
	return false;
}
//根据门的编号找门
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

//类里的查环函数接口(true-有环 false-无环)
bool DOOR_LIST::check_graph() {
	return is_cycle(this->LOGIC_DOOR);
}
//类里的检查是否符合运行条件的接口(true-符合 false-不符合)
bool DOOR_LIST::check_excute() {
	for (int i = 0; i < this->LOGIC_DOOR.size(); i++) {
		if (!this->LOGIC_DOOR[i]->is_exc_correct())
			return false;
	}
	return true;
}
//类里的数据格式化打印电路函数接口
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
