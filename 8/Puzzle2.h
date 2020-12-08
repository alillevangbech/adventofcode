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
	std::vector<bootcode> holder;
	while (std::getline(ifile,line))
	{
		holder.push_back(parseBootcode(line));
	}

	long conq = -1;
	int idx = holder.size()-1;
	string tmpString = "";
	while (conq == -1 || idx == -1)
	{
		tmpString = holder[idx].cmd;
		if (holder[idx].cmd == "jmp") holder[idx].cmd = "nop";
		else if (holder[idx].cmd == "nop") holder[idx].cmd = "jmp";
		else ;

		conq = conqBootcodes(holder);
		holder[idx].cmd = tmpString;
		idx--;
		cout << conq << endl;
	}
	
	std::cout << "accum: " << conq << endl;
}

#endif
