#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>
#include <stack>
#include <string>
#include "../util.h"
using namespace std;
#define MAXSCORE 21
#define MAXBOARD 10
#define STARTSCORE 0

struct game_state {
	public:
	bool p1turn;
	ll space1, space2;
	ll score1, score2;
	bool operator==(const game_state &o) const {
		return o.score1 == score1 &&
			   o.score2 == score2 &&
			   o.space1 == space1 &&
			   o.space2 == space2 &&
			   o.p1turn == p1turn;
	};
};
namespace std {
	template<>
	struct hash<game_state>
	{
		size_t operator()(const game_state &o) const
		{
			return hash<int>()(o.score1) ^
				   hash<int>()(o.score2) ^
				   hash<int>()(o.space1) ^
				   hash<int>()(o.space2);
		}
	};
}

static unordered_map<game_state,pair<ll,ll>> gmap;
game_state move_pawn(ll move, game_state state);
pair<ll,ll> play(game_state state);
pair<ll,ll> add(pair<ll,ll> p1, pair<ll,ll> p2) {return {p1.first + p2.first, p2.second + p1.second};}

int main() 
{
	ll scorep1 = STARTSCORE;
	ll scorep2 = STARTSCORE;
	ll spacep1,spacep2;
	auto input = read_input();
	spacep1 = input[0].back() - '0';
	spacep2 = input[1].back() - '0';
	bool p1turn = true;
	game_state state;
	state.p1turn = p1turn;
	state.space1 = spacep1;
	state.space2 = spacep2;
	state.score1 = scorep1;
	state.score2 = scorep2;
	pair<ll,ll> score = {0,0};
	score = play(state);
	cout << max(score.first,score.second) << endl;

	return 0;
}

pair<ll,ll> play(game_state state) {
	pair<ll,ll> ret {0,0};
	if (state.score1 >= MAXSCORE || state.score2 >= MAXSCORE) {
		if (state.score1 >= MAXSCORE)
			ret.first++;
		else
			ret.second++;

		if (gmap.find(state) == gmap.end())
			gmap[state] = ret;

		return ret;
	}
	
	if (gmap.find(state) != gmap.end())
		return gmap[state];

	game_state new_state;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			for (int k = 1; k <= 3; k++) {
				new_state = move_pawn(i+j+k, state);
				ret = add(ret,play(new_state));
			}
		}
	}

	if (gmap.find(state) == gmap.end())
		gmap[state] = ret;

	return ret;
}

game_state move_pawn(ll move, game_state state) {
	ll space = state.p1turn ? state.space1 : state.space2;
	ll score = state.p1turn ? state.score1 : state.score2;

	space += move;

	if (space % MAXBOARD == 0)
		space = MAXBOARD;
	else if (space > MAXBOARD)
		space %= MAXBOARD;

	score += space;

	if (state.p1turn) {
		state.space1 = space;
		state.score1 = score;
	} else {
		state.space2 = space;
		state.score2 = score;
	}

	state.p1turn = !state.p1turn;
	return state;
}
