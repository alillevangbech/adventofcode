#ifndef __PUZZLE_2_H__
#define __PUZZLE_2_H__

#include "utils.h"
#include <iostream>
#include <fstream>

void second_puzzle()
{
	std::cout << "\n\n ############### SECOND PUZZLE ##############\n\n" << std::endl;
	
	ifstream ifile ("./input.txt");
	std::string line;
	std::vector<bag> holder;

	while (std::getline(ifile,line))
	{
		holder.push_back(parseBag(line));
	}

	string targetBag = "shiny gold";
	int index = findBag(holder,targetBag);
	long result = countBag(holder,holder[index],targetBag) - 1; // -1 for the gold bag itself
	cout << "count: " << result;
	ifile.close();
}

#endif
