
#ifndef __PUZZLE_1_H__
#define __PUZZLE_1_H__ 

#include "utils.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>


void first_puzzle()
{
	std::cout << " ################ PUZZLE ONE ################\n\n " << std::endl;

	std::string file = "./input.txt";
	std::ifstream reader (file);
	std::string line;
	std::vector<int> holder;
	int tmp = 0;
	int sum = 0;

	if (reader.is_open())
	{
	while (std::getline(reader,line))
	{
		holder.push_back(std::stoi(line));
	}

	reader.close();
	for (int i = 0; i < holder.size(); i++)
	{
		tmp = holder[i];
		for (int j = i+1; j < holder.size(); j++)
		{
			sum = tmp+holder[j];
			if (sum == 2020)
				std::cout << "index: " << i << "," << j << "; " << std::endl
						  << "sum multiplied = " << tmp*holder[j]
						  << std::endl; 
		}
	}

	}
	else std::cout << "file not open" << std::endl;
}
#endif
