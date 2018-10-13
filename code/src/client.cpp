#include"client.hpp"
int CLIENT::number_of_circuit = 0;
void print_1() {
	std::cout << "请根据下面序号对应的操作以进行你想要的操作：" << std::endl;
	std::cout << "1 - 添加门元件" << std::endl;
	std::cout << "2 - 连接门元件" << std::endl;
	std::cout << "3 - 断开门元件的连接" << std::endl;
	std::cout << "4 - 删除门元件" << std::endl;
	std::cout << "5 - 设定输入及输出" << std::endl;
	std::cout << "6 - 查环" << std::endl;
	std::cout << "7 - 运行" << std::endl;
	std::cout << "8 - 打印类" << std::endl;
	std::cout << "9 - 退出" << std::endl;
	std::cout << "请输入你的选择，并以ENTER键进行录入：" ;
}
void print_2() {
	std::cout << "请选择要添加的逻辑门的类型：" << std::endl;
	std::cout << "1 - 与门" << std::endl;
	std::cout << "2 - 非门" << std::endl;
	std::cout << "3 - 或门 " << std::endl;
	std::cout << "4 - 异或门" << std::endl;
	std::cout << "5 - 与非门" << std::endl;
	std::cout << "6 - 返回" << std::endl;
	std::cout <<"请输入你的选择，并以ENTER键进行录入：";
}
void print_3() {
	std::cout << "请根据下面序号对应的操作以进行你想要打印的操作：" << std::endl;
	std::cout << "1 - 打印各电路之间的连接关系" << std::endl;
	std::cout << "2 - 打印输出的结果" << std::endl;
	std::cout << "请输入你想要的操作:" ;
}

CLIENT::CLIENT()
{
	std::cout << "请输入你的姓名：";
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
	//输入异常处理
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
			std::cout << "输入属于非数字，属于异常，请重新输入：" ;
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
	default:std::cout << "输入字符不符合要求，返回上一层！" << std::endl;
		return false;
		break;
	}
}
void CLIENT::RUN() {
	int flag = 0;
	std::cout << "成功进入运行!" << std::endl;
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
				std::cout << "输入属于非数字，属于异常，请重新输入：";
			}
		}
		switch (choice)
		{
		case 1:
		{
			system("cls");
			if (this->door_create()) {
				std::cout << "创建成功！" << std::endl;
			}
			else {
				std::cout << "创建失败！" << std::endl;
			}
		}
			break;
		case 2:
		{
			system("cls");
			std::cout << "连接操作" << std::endl;
			std::cout << "请输入作为输入端的门的标志：";
			//输入异常处理
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
					std::cout << "输入属于非数字，属于异常，请重新输入：";
				}
			}
			std::cout << "请输入作为输出端的门的标志：";
			//输入异常处理
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
					std::cout << "输入属于非数字，属于异常，请重新输入：";
				}
			}

			if (this->door_list->is_here_door(i) && this->door_list->is_here_door(j)) {
				if (this->door_list->connect(this->door_list->find_door(i), this->door_list->find_door(j))) {
					std::cout << "连接成功!!" << std::endl;
				}
				else {
					std::cout << "连接失败" << std::endl;
				}
			}
			else {
				std::cout << "输入存在着不存在的门!!" << std::endl;
			}
		}
			break;
		case 3:
		{
			system("cls");
			std::cout << "断开操作" << std::endl;
			std::cout << "请输入作为输入端的门的标志：";
			//输入异常处理
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
					std::cout << "输入属于非数字，属于异常，请重新输入：";
				}
			}
			std::cout << "请输入作为输出端的门的标志：";
			//输入异常处理
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
					std::cout << "输入属于非数字，属于异常，请重新输入：";
				}
			}
			if (this->door_list->is_here_door(i) && this->door_list->is_here_door(j)) {
				if (this->door_list->cut(this->door_list->find_door(i), i, this->door_list->find_door(j), j)) {
					std::cout << "断开连接成功!!" << std::endl;
				}
				else {
					std::cout << "断开连接失败!!" << std::endl;
				}
			}
			else {
				std::cout << "输入存在着不存在的门!!" << std::endl;
			}
		}
			break;
		case 4:
		{
			system("cls");
			std::cout << "请输入要删除的门的标志：";
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
						//删去输出名称数组里相对应的下标指定的元素
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
						//删去输入名称数组里相对应的下标指定的元素
						for (int i_NUM = in_NUM; i_NUM <in_num-1; i_NUM++) {
							this->in_name[i_NUM] = this->in_name[i_NUM + 1];
						}
						this->inputs.erase(its);
						in_num--;
						break;
					}
				}
				if (this->door_list->remove_door(i)) {

					std::cout << "删除成功!!" << std::endl;
				}
				else {
					std::cout << "删除失败!!" << std::endl;
				}
			}
			else {
				std::cout << "不存在该门!!" << std::endl;
			}
		}
			break;
		case 5:
		{
			system("cls");
			std::cout << "请输入要添加的输入端(1)(默认为高电平)或输出端(2)：";
			int i_o;
			std::string i_o_name;
			//输入异常处理
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
					std::cout << "输入属于非数字，属于异常，请重新输入：";
				}
			}
			std::cout << "请输入其名字：";
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
				std::cout << "添加成功!!" << std::endl;
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
				std::cout << "添加成功!!" << std::endl;
			}
				break;
			default:std::cout << "输入命令不符合要求，返回上一层!!" << std::endl;
				break;
			}
		break;
		}
		case 6:
		{
			system("cls");
			if (!(this->door_list->check_graph())) {
				std::cout << "不存在环!!" << std::endl;
			}
		}
			break;
		case 7:
		{
			system("cls");
			if (this->door_list->check_graph()) {
				std::cout << "电路连接存在问题，请检查并修改！！" << std::endl;
				break;
			}
			if (this->door_list->check_excute()) {
				for (int n1 = 0; n1 < this->in_num; n1++) {
					std::cout << "请输入 " << this->in_name[n1] << " 的电平(0-低 1(或除0外其他整数)-高):";
					int one_;
					//输入异常处理
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
							std::cout << "输入属于非数字，属于异常，请重新输入：";
						}
					}
					if (one_ == 0)this->inputs[n1]->setelectricity(false);
					else this->inputs[n1]->setelectricity(true);
				}
				this->door_list->excuting();
			}
			else {
				std::cout << "电路连接存在问题，请检查并修改！！" << std::endl;
			}
		}
		break;
		case 8:
		{
			system("cls");
			print_3();
			int nnn;
			//输入异常处理
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
					std::cout << "输入属于非数字，属于异常，请重新输入：";
				}
			}
			switch (nnn)
			{
			case 1:
				this->door_list->read();
				break;
			case 2:
				std::cout << "输入类:" << std::endl;
				for (int n2 = 0; n2 < this->in_num; n2++) {
					std::cout << this->in_name[n2] << " : " << this->inputs[n2]->getelectricity() << std::endl;
				}
				std::cout << "输出类:" << std::endl;
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
		default:std::cout << "输入命令不符合要求，返回上一层!!" << std::endl;
			break;
		}
	}
	
}
