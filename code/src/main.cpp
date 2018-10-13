#include <iostream>       // std::cerr
#include <stdexcept>      // std::out_of_range
#include<exception>
#include <vector>         // std::vector
#include<string>
#include"door.hpp"
#include"Door_List.hpp"
#include"client.hpp"

int main(void) {
	CLIENT *pom = new CLIENT();
	pom->RUN();
	system("pause");
	return 0;
}
