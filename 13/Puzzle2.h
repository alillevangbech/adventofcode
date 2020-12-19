#ifndef __PUZZLE_2_H__
#define __PUZZLE_2_H__

#include "utils.h"
#include <iostream>

using namespace std;
void second_puzzle()
{
	std::cout << "\n\n ############### SECOND PUZZLE ##############\n\n" << std::endl;
	map<int,int> map = loaddata2();
	unsigned long ts;
	bool result;
	while (result != true)
	{
		result = testTimestamp2(map,ts);
	}
}

#endif
