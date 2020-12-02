
#ifndef __PUZZLE_1_H__
#define __PUZZLE_1_H__ 

#include "utils.h"
#include <iostream>
#include <fstream>

void first_puzzle()
{
	std::cout << " ################ PUZZLE ONE ################\n\n " << std::endl;

	std::ifstream ifile ("./input.txt");
	std::string line;
	std::string pwrd;
	int* lower = new int;
	int* upper = new int;
	int valid_count = 0;
	int word_count = 0;
	while (std::getline(ifile,line))
	{
		getLimits(line,lower,upper);
		pwrd = password(line);
		word_count = std::count(pwrd.begin(),pwrd.end(),password_char(line));
		if (*lower <= word_count && word_count <= *upper) valid_count++;
	}
	std::cout << "valid passwords: " << valid_count;

	ifile.close();
	delete lower;
	delete upper;
}
#endif
