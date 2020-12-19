
#ifndef __PUZZLE_1_H__
#define __PUZZLE_1_H__ 

#include "utils.h"
#include <iostream>

void first_puzzle()
{
	std::cout << " ################ PUZZLE ONE ################\n\n " << std::endl;

	vector<int> v = loaddata();
	vector<number> game_vec;
	int turn = 1;
	int answer = 0;

	// starting numbers;
	for (int n : v)
	{
		answer = n;
		insertionsort(game_vec,createnumber(answer,turn));
		cout << turn << ": " << answer << endl;
		turn++;
		//printv(game_vec);
	}

	//cout << "hi" << endl;
	// infinite game;
	while (turn < 10)
	{
		answer = playturn(game_vec,turn,answer);
		cout << turn << ": " << answer << endl;
		//printv(game_vec);
		turn++;
	}

	cout << turn << ": " << answer << endl;




}
#endif
