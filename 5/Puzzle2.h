#ifndef __PUZZLE_2_H__
#define __PUZZLE_2_H__

#include "utils.h"
#include <iostream>

void second_puzzle()
{
	std::cout << "\n\n ############### SECOND PUZZLE ##############\n\n" << std::endl;
	
	ifstream ifile ("./input.txt");
	std::string line;
	long result = 0;
	int tmp;
	std::vector<string> holder;
	while (getline(ifile,line))
	{
		holder.push_back(line);
	}
	ifile.close();
	
	
	vector<int> list(128*8 + 8);
	for (int i = 0; i < holder.size(); i++)
	{
		int tmp = seat_id(holder[i]);
		list[tmp] = tmp;
		result = tmp > result ? tmp : result;
	}
	
	bool hitzero = false;
	bool hitnumber = false;;
	int seatnumber = 0;
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i] != 0) hitnumber = true;
		if (hitnumber && list[i] == 0) hitzero = true;
		if (hitnumber && hitzero)
		{
			seatnumber = i;
			break;
		}
	}
	

	


	std::cout << result << std::endl;
	std::cout << seatnumber;

}

#endif
