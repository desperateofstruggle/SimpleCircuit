#ifndef DOOR_LIST_HPP
#define DOOR_LIST_HPP
#include<iostream>
#include<vector>
#include<exception>
#include <stdexcept> 
#include"door.hpp"

class DOOR_LIST {
public:
	DOOR_LIST();
	~DOOR_LIST();
	bool connect(DOOR*, DOOR*);
	bool cut(DOOR*,int, DOOR*,int);
	
	void add_door(DOOR*);
	void add_outdoor(DOOR*);
	bool remove_door(int);
	bool is_here_door(int);
	
	DOOR* find_door(int);
	
	bool check_graph();
	bool check_excute();
	void excuting();
	void read();
	void remove_all();
private:
	std::vector<DOOR*>LOGIC_DOOR;
	std::vector<DOOR*>OUT_PRINT;
};



#endif // !DOOR_LIST_HPP
