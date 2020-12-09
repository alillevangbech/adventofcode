#ifndef __PUZZLE_2_H__
#define __PUZZLE_2_H__

#include "utils.h"
#include <iostream>
#include <fstream>

using namespace std;
void second_puzzle()
{
	std::cout << "\n\n ############### SECOND PUZZLE ##############\n\n" << std::endl;
	
	ifstream ifile ("./input.txt");
	string line;
	size_t preamble = 25;
	std::vector<long> holder;
	while (getline(ifile,line)) holder.push_back(std::stol(line));
	ifile.close();
	
	std::cout << getXMASWeakness(holder,preamble) << endl;

}

#endif
