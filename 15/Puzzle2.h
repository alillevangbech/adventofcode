#ifndef __PUZZLE_2_H__
#define __PUZZLE_2_H__

#include "utils.h"
#include <iostream>

void second_puzzle()
{
	std::cout << "\n\n ############### SECOND PUZZLE ##############\n\n" << std::endl;

	vector<int> v = loaddata();
	vector<number> game_vec;
	int turn = 1;
	int answer = 0;

	// starting numbers;
	for (int n : v)
	{
		answer = playturn(game_vec,turn,n);
		//cout << turn << ": " << answer << endl;
		turn++;
	}

	// infinite game;
	while (turn < 30000000)
	{
		answer = playturn(game_vec,turn,answer);
		turn++;
		cout << turn << ": " << answer << endl;
	}

	cout << turn << ": " << answer << endl;

}


#endif
