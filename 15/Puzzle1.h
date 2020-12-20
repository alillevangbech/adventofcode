
#ifndef __PUZZLE_1_H__
#define __PUZZLE_1_H__ 

#include "utils.h"
#include <iostream>

void first_puzzle()
{
	std::cout << " ################ PUZZLE ONE ################\n\n " << std::endl;
	string s = "0,13,16,17,1,10,6";
	vector<int> v = loaddata(s);
	int turns = 2020;
	cout << "startingnumbers: " << s << endl;
	int answer = playturns(v,turns);
	cout << "turns: " << turns << "  answer: " << answer;
}
#endif
