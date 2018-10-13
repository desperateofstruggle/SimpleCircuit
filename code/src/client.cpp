#include"client.hpp"
int CLIENT::number_of_circuit = 0;
void print_1() {
	std::cout << "�����������Ŷ�Ӧ�Ĳ����Խ�������Ҫ�Ĳ�����" << std::endl;
	std::cout << "1 - �����Ԫ��" << std::endl;
	std::cout << "2 - ������Ԫ��" << std::endl;
	std::cout << "3 - �Ͽ���Ԫ��������" << std::endl;
	std::cout << "4 - ɾ����Ԫ��" << std::endl;
	std::cout << "5 - �趨���뼰���" << std::endl;
	std::cout << "6 - �黷" << std::endl;
	std::cout << "7 - ����" << std::endl;
	std::cout << "8 - ��ӡ��" << std::endl;
	std::cout << "9 - �˳�" << std::endl;
	std::cout << "���������ѡ�񣬲���ENTER������¼�룺" ;
}
void print_2() {
	std::cout << "��ѡ��Ҫ��ӵ��߼��ŵ����ͣ�" << std::endl;
	std::cout << "1 - ����" << std::endl;
	std::cout << "2 - ����" << std::endl;
	std::cout << "3 - ���� " << std::endl;
	std::cout << "4 - �����" << std::endl;
	std::cout << "5 - �����" << std::endl;
	std::cout << "6 - ����" << std::endl;
	std::cout <<"���������ѡ�񣬲���ENTER������¼�룺";
}
void print_3() {
	std::cout << "�����������Ŷ�Ӧ�Ĳ����Խ�������Ҫ��ӡ�Ĳ�����" << std::endl;
	std::cout << "1 - ��ӡ����·֮������ӹ�ϵ" << std::endl;
	std::cout << "2 - ��ӡ����Ľ��" << std::endl;
	std::cout << "����������Ҫ�Ĳ���:" ;
}

CLIENT::CLIENT()
{
	std::cout << "���������������";
	std::cin >> this->name;
	std::cout << "Welcome to simple_Circuit World , " << this->name <<" !! "<< std::endl;
	this->door_list = new DOOR_LIST();
	in_num = 0;
	out_num = 0;
	counting_label = -3;
}

CLIENT::~CLIENT()
{
	if(this->door_list!=NULL)
		delete this->door_list;
}
bool CLIENT::door_create() {
	print_2();
	int ch;
	int flag = 1;
	//�����쳣����
	while (flag != 0) {
		std::cin >> ch;
		try {
			if (std::cin.fail())
				throw 1;
			flag = 0;
		}
		catch (int) {
			std::cin.clear();
			std::cin.sync();
			std::cin.ignore();
			std::cout << "�������ڷ����֣������쳣�����������룺" ;
		}
	}
	
	switch (ch)
	{
	case 1:
	{
		DOOR * temp = new AND_DOOR();
		temp->setlabel(number_of_circuit++);
		this->door_list->add_door(temp);
		return true;
		break;
	}
	case 2:
	{
		DOOR * temp1 = new NOT_DOOR();
		temp1->setlabel(number_of_circuit++);
		this->door_list->add_door(temp1);
		return true;
	}
		break;
	case 3:
	{
		DOOR * temp2 = new OR_DOOR();
		temp2->setlabel(number_of_circuit++);
		this->door_list->add_door(temp2);
		return true;
	}
		break;
	case 4:
	{
		DOOR * temp3 = new XOR_DOOR();
		temp3->setlabel(number_of_circuit++);
		this->door_list->add_door(temp3);
		return true;
	}
		break;
	case 5:
	{
		DOOR * temp3 = new NAND_DOOR();
		temp3->setlabel(number_of_circuit++);
		this->door_list->add_door(temp3);
		return true;
	}
		break;
	default:std::cout << "�����ַ�������Ҫ�󣬷�����һ�㣡" << std::endl;
		return false;
		break;
	}
}
void CLIENT::RUN() {
	int flag = 0;
	std::cout << "�ɹ���������!" << std::endl;
	int choice;
	while (flag == 0) {
		print_1();
		int flagss = 1;
		while (flagss != 0) {
			std::cin >> choice;
			try {
				if (std::cin.fail())
					throw 1;
				flagss = 0;
			}
			catch (int) {
				std::cin.clear();
				std::cin.sync();
				std::cin.ignore();
				std::cout << "�������ڷ����֣������쳣�����������룺";
			}
		}
		switch (choice)
		{
		case 1:
		{
			system("cls");
			if (this->door_create()) {
				std::cout << "�����ɹ���" << std::endl;
			}
			else {
				std::cout << "����ʧ�ܣ�" << std::endl;
			}
		}
			break;
		case 2:
		{
			system("cls");
			std::cout << "���Ӳ���" << std::endl;
			std::cout << "��������Ϊ����˵��ŵı�־��";
			//�����쳣����
			int flags = 1;
			int i, j;
			while (flags != 0) {
				std::cin >> i;
				try {
					if (std::cin.fail())
						throw 1;
					flags = 0;
				}
				catch (int) {
					std::cin.clear();
					std::cin.sync();
					std::cin.ignore();
					std::cout << "�������ڷ����֣������쳣�����������룺";
				}
			}
			std::cout << "��������Ϊ����˵��ŵı�־��";
			//�����쳣����
			int flagst = 1;
			while (flagst != 0) {
				std::cin >> j;
				try {
					if (std::cin.fail())
						throw 1;
					flagst = 0;
				}
				catch (int) {
					std::cin.clear();
					std::cin.sync();
					std::cin.ignore();
					std::cout << "�������ڷ����֣������쳣�����������룺";
				}
			}

			if (this->door_list->is_here_door(i) && this->door_list->is_here_door(j)) {
				if (this->door_list->connect(this->door_list->find_door(i), this->door_list->find_door(j))) {
					std::cout << "���ӳɹ�!!" << std::endl;
				}
				else {
					std::cout << "����ʧ��" << std::endl;
				}
			}
			else {
				std::cout << "��������Ų����ڵ���!!" << std::endl;
			}
		}
			break;
		case 3:
		{
			system("cls");
			std::cout << "�Ͽ�����" << std::endl;
			std::cout << "��������Ϊ����˵��ŵı�־��";
			//�����쳣����
			int flags = 1;
			int i, j;
			while (flags != 0) {
				std::cin >> i;
				try {
					if (std::cin.fail())
						throw 1;
					flags = 0;
				}
				catch (int) {
					std::cin.clear();
					std::cin.sync();
					std::cin.ignore();
					std::cout << "�������ڷ����֣������쳣�����������룺";
				}
			}
			std::cout << "��������Ϊ����˵��ŵı�־��";
			//�����쳣����
			int flagst = 1;
			while (flagst != 0) {
				std::cin >> j;
				try {
					if (std::cin.fail())
						throw 1;
					flagst = 0;
				}
				catch (int) {
					std::cin.clear();
					std::cin.sync();
					std::cin.ignore();
					std::cout << "�������ڷ����֣������쳣�����������룺";
				}
			}
			if (this->door_list->is_here_door(i) && this->door_list->is_here_door(j)) {
				if (this->door_list->cut(this->door_list->find_door(i), i, this->door_list->find_door(j), j)) {
					std::cout << "�Ͽ����ӳɹ�!!" << std::endl;
				}
				else {
					std::cout << "�Ͽ�����ʧ��!!" << std::endl;
				}
			}
			else {
				std::cout << "��������Ų����ڵ���!!" << std::endl;
			}
		}
			break;
		case 4:
		{
			system("cls");
			std::cout << "������Ҫɾ�����ŵı�־��";
			int i;
			std::cin >> i;
			if (this->door_list->is_here_door(i)) {
				int insides = this->door_list->find_door(i)->get_inside_vector_size();
				int outsides = this->door_list->find_door(i)->get_outside_vector_size();
				for (int j = 0; j < insides; j++) {
					this->door_list->cut(this->door_list->find_door(i)->getinput(j), this->door_list->find_door(i)->getinput(j)->getlabel(), this->door_list->find_door(i), this->door_list->find_door(i)->getlabel());
				}
				for (int k = 0; k < outsides; k++) {
					this->door_list->cut(this->door_list->find_door(i), this->door_list->find_door(i)->getlabel(), this->door_list->find_door(i)->getoutput(k), this->door_list->find_door(i)->getoutput(k)->getlabel());
				}
				int out_NUM=0;
				for (std::vector<OUTPUT_DOOR*>::iterator it =this-> outputs.begin(); it != outputs.end(); it++,out_NUM++) {
					if ((*it)->getlabel() == this->door_list->find_door(i)->getlabel()){
						//ɾȥ����������������Ӧ���±�ָ����Ԫ��
						for (int o_NUM = out_NUM; o_NUM < this->out_num-1; o_NUM++) {
							this->out_name[o_NUM] = this->out_name[o_NUM + 1];
						}
						this->outputs.erase(it);
						out_num--;
						break;
					}
				}
				int in_NUM = 0;
				for (std::vector<INPUT_DOOR*>::iterator its = this->inputs.begin(); its != inputs.end(); its++,in_NUM++) {
					if ((*its)->getlabel() == this->door_list->find_door(i)->getlabel()) {
						//ɾȥ�����������������Ӧ���±�ָ����Ԫ��
						for (int i_NUM = in_NUM; i_NUM <in_num-1; i_NUM++) {
							this->in_name[i_NUM] = this->in_name[i_NUM + 1];
						}
						this->inputs.erase(its);
						in_num--;
						break;
					}
				}
				if (this->door_list->remove_door(i)) {

					std::cout << "ɾ���ɹ�!!" << std::endl;
				}
				else {
					std::cout << "ɾ��ʧ��!!" << std::endl;
				}
			}
			else {
				std::cout << "�����ڸ���!!" << std::endl;
			}
		}
			break;
		case 5:
		{
			system("cls");
			std::cout << "������Ҫ��ӵ������(1)(Ĭ��Ϊ�ߵ�ƽ)�������(2)��";
			int i_o;
			std::string i_o_name;
			//�����쳣����
			int flags = 1;
			while (flags != 0) {
				std::cin >> i_o;
				try {
					if (std::cin.fail())
						throw 1;
					flags = 0;
				}
				catch (int) {
					std::cin.clear();
					std::cin.sync();
					std::cin.ignore();
					std::cout << "�������ڷ����֣������쳣�����������룺";
				}
			}
			std::cout << "�����������֣�";
			std::cin >> i_o_name;

			switch (i_o)
			{
			case 1:
			{
				in_name[in_num++] = i_o_name;
				INPUT_DOOR* temp = new INPUT_DOOR();
				temp->setlabel(counting_label--);
				temp->setelectricity(true);
				this->door_list->add_door(temp);
				this->inputs.push_back(temp);
				std::cout << "��ӳɹ�!!" << std::endl;
			}
			break;
			case 2:
			{
				out_name[out_num++] = i_o_name;
				OUTPUT_DOOR* temp = new OUTPUT_DOOR();
				temp->setlabel(counting_label--);
				this->door_list->add_door(temp);
				this->door_list->add_outdoor(temp);
				this->outputs.push_back(temp);
				std::cout << "��ӳɹ�!!" << std::endl;
			}
				break;
			default:std::cout << "�����������Ҫ�󣬷�����һ��!!" << std::endl;
				break;
			}
		break;
		}
		case 6:
		{
			system("cls");
			if (!(this->door_list->check_graph())) {
				std::cout << "�����ڻ�!!" << std::endl;
			}
		}
			break;
		case 7:
		{
			system("cls");
			if (this->door_list->check_graph()) {
				std::cout << "��·���Ӵ������⣬���鲢�޸ģ���" << std::endl;
				break;
			}
			if (this->door_list->check_excute()) {
				for (int n1 = 0; n1 < this->in_num; n1++) {
					std::cout << "������ " << this->in_name[n1] << " �ĵ�ƽ(0-�� 1(���0����������)-��):";
					int one_;
					//�����쳣����
					int flags = 1;
					while (flags != 0) {
						std::cin >> one_;
						try {
							if (std::cin.fail())
								throw 1;
							flags = 0;
						}
						catch (int) {
							std::cin.clear();
							std::cin.sync();
							std::cin.ignore();
							std::cout << "�������ڷ����֣������쳣�����������룺";
						}
					}
					if (one_ == 0)this->inputs[n1]->setelectricity(false);
					else this->inputs[n1]->setelectricity(true);
				}
				this->door_list->excuting();
			}
			else {
				std::cout << "��·���Ӵ������⣬���鲢�޸ģ���" << std::endl;
			}
		}
		break;
		case 8:
		{
			system("cls");
			print_3();
			int nnn;
			//�����쳣����
			int flags = 1;
			while (flags != 0) {
				std::cin >> nnn;
				try {
					if (std::cin.fail())
						throw 1;
					flags = 0;
				}
				catch (int) {
					std::cin.clear();
					std::cin.sync();
					std::cin.ignore();
					std::cout << "�������ڷ����֣������쳣�����������룺";
				}
			}
			switch (nnn)
			{
			case 1:
				this->door_list->read();
				break;
			case 2:
				std::cout << "������:" << std::endl;
				for (int n2 = 0; n2 < this->in_num; n2++) {
					std::cout << this->in_name[n2] << " : " << this->inputs[n2]->getelectricity() << std::endl;
				}
				std::cout << "�����:" << std::endl;
				for (int n3 = 0; n3 < this->out_num; n3++) {
					std::cout << this->out_name[n3] << " : " << this->outputs[n3]->getelectricity() << std::endl;
				}
				break;
			default:
				break;
			}
		}
			break;
		case 9:
		{
			this->door_list->remove_all();
			std::cout << *this << std::endl;
			flag = 1;
		}
			break;
		default:std::cout << "�����������Ҫ�󣬷�����һ��!!" << std::endl;
			break;
		}
	}
	
}
