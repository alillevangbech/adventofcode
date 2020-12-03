#ifndef __PUZZLE_2_H__
#define __PUZZLE_2_H__

#include "utils.h"
#include <iostream>
#include <fstream>

void second_puzzle()
{
	std::cout << "\n\n ############### SECOND PUZZLE ##############\n\n" << std::endl;
	std::ifstream ifile ("./input.txt"); std::vector<std::string> holder; std::string line;
	while (std::getline(ifile,line)) holder.push_back(line); ifile.close();

	std::cout << count_trees(holder,1,1)*count_trees(holder,3,1)*count_trees(holder,5,1)*count_trees(holder,7,1)*count_trees(holder,1,2);
}

#endif
