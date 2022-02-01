#include <bits/stdc++.h>
#include <stack>
#include <string>
#include "../util.h"
using namespace std;
#define MAXSCORE 1000
#define MAXBOARD 10
#define STARTSCORE 0
#define DIE 100
static ll die100 = 0;
static ll die100rolls = 0;

ll roll_deterministic() {
	die100++;
	die100rolls++;

	if (die100 % DIE == 0)
		die100 = DIE;
	else if (die100 > DIE)
		die100 %= DIE;

	return die100;
}

void move_pawn(ll move, ll &score, ll &space) {
	//cout << "move: " << move << " | score: " << score <<" | space: " << space << endl;
	space += move;

	if (space % MAXBOARD == 0)
		space = MAXBOARD;
	else if (space > MAXBOARD)
		space %= MAXBOARD;

	score += space;
	//cout << "after -> move: " << move << " | score: " << score <<" | space: " << space << endl;
}

int main() 
{
	ll scorep1 = STARTSCORE;
	ll scorep2 = STARTSCORE;
	ll spacep1,spacep2;
	ll roll;
	auto input = read_input();
	spacep1 = input[0].back() - '0';
	spacep2 = input[1].back() - '0';
	bool p1turn = true;
	while (scorep1 < MAXSCORE && scorep2 < MAXSCORE) {
		roll = 0;
		for (int i = 0; i < 3; i++)
			roll += roll_deterministic();
		if (p1turn) {
			move_pawn(roll, scorep1, spacep1);
		} else {
			move_pawn(roll, scorep2, spacep2);
		}

		p1turn = !p1turn;
	}
	ll loser = scorep1 < MAXSCORE ? scorep1 : scorep2;
	cout << loser*die100rolls << endl;

	return 0;
}
