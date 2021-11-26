
#ifndef __PUZZLE_1_H__
#define __PUZZLE_1_H__ 

#include "utils.h"
#include <iostream>
#include <fstream>

void first_puzzle()
{
	std::cout << " ################ PUZZLE ONE ################\n\n " << std::endl;
	
	std::ifstream ifile ("./input.txt"); std::vector<std::string> holder; std::string line;
	while (std::getline(ifile,line)) holder.push_back(line); ifile.close();
	std::cout << count_trees(holder,3,1);
}
#endif
