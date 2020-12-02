#ifndef __PUZZLE_2_H__
#define __PUZZLE_2_H__

#include "utils.h"
#include <iostream>
#include <fstream>

void second_puzzle()
{
	std::cout << "\n\n ############### SECOND PUZZLE ##############\n\n" << std::endl;
	std::ifstream ifile ("./input.txt");
	std::string line;
	std::string pwrd;
	int* lower = new int;
	int* upper = new int;
	int valid_count = 0;
	int word_count = 0;
	char pwrd_char = ' ';
	while (std::getline(ifile,line))
	{
		getLimits(line,lower,upper);
		pwrd = password(line);
		pwrd_char = password_char(line);
		if (pwrd[*lower - 1] == pwrd_char && pwrd[*upper - 1] == pwrd_char) ;
		else if (pwrd[*lower - 1] == pwrd_char || pwrd[*upper - 1] == pwrd_char) valid_count++;
		else ;
	}
	std::cout << "valid passwords: " << valid_count;
	
	ifile.close();

}

#endif
