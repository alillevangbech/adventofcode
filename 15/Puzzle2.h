#ifndef __PUZZLE_2_H__
#define __PUZZLE_2_H__

#include "utils.h"
#include <iostream>

void second_puzzle()
{
	std::cout << "\n\n ############### SECOND PUZZLE ##############\n\n" << std::endl;

	string s = "0,13,16,17,1,10,6";
	vector<int> v = loaddata(s);
	int turns = 30000000;
	cout << "startingnumbers: " << s << endl;
	int answer = playturns(v,turns);
	cout << "turns: " << turns << "  answer: " << answer;

}


#endif
