
#ifndef __PUZZLE_1_H__
#define __PUZZLE_1_H__ 

#include "utils.h"
#include <iostream>

using namespace std;

void first_puzzle()
{
	std::cout << " ################ PUZZLE ONE ################\n\n " << std::endl;
	vector<instruct> holder = loaddata();
	int nav = navigate(holder);
	cout << "manhatten: " <<  nav << endl;
}
#endif
