#ifndef __PUZZLE_2_H__
#define __PUZZLE_2_H__

#include "utils.h"
#include <iostream>

void second_puzzle()
{
	std::cout << "\n\n ############### SECOND PUZZLE ##############\n\n" << std::endl;
	vector<int> holder = loaddata();
	holder.push_back(holder.back()+3);
	holder.push_back(0);
	

	std::cout << algo2(holder) << endl;
	
}

#endif
