
#ifndef __PUZZLE_1_H__
#define __PUZZLE_1_H__ 

#include "utils.h"
#include <iostream>

void first_puzzle()
{
	std::cout << " ################ PUZZLE ONE ################\n\n " << std::endl;
	vector<int> holder = loaddata();
	int timestamp = holder.front();
	int min = timestamp;
	int minID = -1;
	for (int i = 1; i < holder.size(); i++)
	{
		if (holder[i] - (timestamp % holder[i]) < min)
		{
			minID = holder[i];
			min = holder[i] - (timestamp % holder[i]);
		}
	}
	cout << "RESULT" << min*minID << endl;
}
#endif
