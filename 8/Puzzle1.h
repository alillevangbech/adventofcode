
#ifndef __PUZZLE_1_H__
#define __PUZZLE_1_H__ 

#include "utils.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void first_puzzle()
{
	std::cout << " ################ PUZZLE ONE ################\n\n " << std::endl;
	std::ifstream ifile ("./input.txt");
	std::string line;
	std::vector<bootcode> holder;
	while (std::getline(ifile,line))
	{
		holder.push_back(parseBootcode(line));
	}

	long accum = accumBootcodes(holder);
	std::cout << "accum: " << accum << endl;
}
#endif
