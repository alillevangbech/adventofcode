
#ifndef __PUZZLE_1_H__
#define __PUZZLE_1_H__ 

#include "utils.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <deque>

using namespace std;




void first_puzzle()
{
	std::cout << " ################ PUZZLE ONE ################\n\n " << std::endl;

	ifstream ifile ("./input.txt");
	string line;
	size_t preamble = 25;
	std::vector<long> holder;
	while (getline(ifile,line)) holder.push_back(std::stol(line));
	ifile.close();
	cout << getXMASResult(holder,preamble) << endl;
}
#endif
