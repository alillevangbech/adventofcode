#ifndef __PUZZLE_2_H__
#define __PUZZLE_2_H__

#include "utils.h"
#include <iostream>
#include <fstream>
#include <vector>

void second_puzzle()
{
	std::cout << "\n\n ############### SECOND PUZZLE ##############\n\n" << std::endl;
	std::string file = "./input.txt";
	std::ifstream reader (file);
	std::string line;
	std::vector<int> holder;
	int tmp1 = 0;
	int tmp2 = 0;
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
		tmp1 = holder[i];
		for (int j = i+1; j < holder.size(); j++)
		{
			tmp2 = holder[j];
			for (int k = j+1; k < holder.size(); k++)
			{
				sum = tmp1 + tmp2 + holder[k];
				if (sum == 2020)
					std::cout << "index: " << i << "," << j  << "," << k << "; " << std::endl
							  << "sum multiplied = " << tmp1*tmp2*holder[k]
							  << std::endl; 
			}
		}
	}
	}
	else std::cout << "file not open" << std::endl;
}

#endif
