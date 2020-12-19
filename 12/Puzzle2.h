#ifndef __PUZZLE_2_H__
#define __PUZZLE_2_H__

#include "utils.h"
#include <iostream>

void second_puzzle()
{
	std::cout << "\n\n ############### SECOND PUZZLE ##############\n\n" << std::endl;
	vector<instruct> holder = loaddata();
	int nav = navigate2(holder);
	cout << "manhatten: " <<  nav << endl;
}

#endif
