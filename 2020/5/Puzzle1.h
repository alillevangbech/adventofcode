
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
	

	ifstream ifile ("./input.txt");
	std::string line;
	long result = 0;
	int tmp;
	while (getline(ifile,line))
	{
		int tmp = seat_id(line);
		result = tmp > result ? tmp : result;
	}
	
	std::cout << result;
	ifile.close();

}
#endif
