#ifndef CLIENT_HPP
#define CLIENT_HPP
#include"door.hpp"
#include"Door_List.hpp"
#include<exception>
#include <stdexcept> 
#include<Windows.h>
class CLIENT
{
public:
	CLIENT();
	~CLIENT();
	void RUN();
	bool door_create();
	static int number_of_circuit;
	friend std::ostream &operator<<(std::ostream &output, const CLIENT &D) {
		output<<  "Goodbye , " << D.name<<" .Good luck to you!!\n" ;
		return output;
	}
private:
	DOOR_LIST *door_list;
	std::string name;
	std::vector<INPUT_DOOR*>inputs;
	std::vector<OUTPUT_DOOR*>outputs;
	int in_num;
	int out_num;
	int counting_label;
	std::string in_name[100];
	std::string out_name[100];
};

#endif // !CLIENT_HPP
