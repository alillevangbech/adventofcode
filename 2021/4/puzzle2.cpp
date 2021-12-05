#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>
#include <iterator>
#include <numeric>
#include "../util.h"
using namespace std;
#define n 5
#define board vector<vector<pair<int,bool>>>
#define allboard vector<board>
void pGame(const allboard& b) {
	for (int z = 0; z < b.size(); z++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << b[z][i][j].first << ";" << b[z][i][j].second << "\t";
			}
			cout << endl;
		}
		cout << endl;
	}
}

void pBoard(const board& b) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << b[i][j].first << ";" << b[i][j].second << "\t";
		}
		cout << endl;
	}
}

void flipNumber(board& b, int number) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (b[i][j].first == number) {
				b[i][j].second = true;
				return;
			}
		}
	}
}

int sumBoard(const board& b) {
	int x = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!b[i][j].second) {
				x += b[i][j].first; 
			}
		}
	}
	return x;
}

bool checkrow(board& b, int row)
{
	int i = 0;
	for (auto x : b[row])
		i += x.second;
	return n == i;
}

bool checkcol(board& b, int col)
{
	int i = 0;
	for (int x = 0; x < n; x++) {
		i += b[x][col].second;
	}
	return n == i;
}



int main() 
{
	auto input = read_input();
	vector<int> draws;

	std::stringstream ss(input[0]);
    for (int i; ss >> i;) {
        draws.push_back(i);    
        if (ss.peek() == ',')
            ss.ignore();
    }

	bool hack = false;
	int x1,x2,x3,x4,x5;
	allboard game;
	int ret, count = -1;
	board b = board(n);
	for (auto s : input) {
		if (!hack) {hack = !hack; continue;};
		sscanf(s.c_str(), "%d %d %d %d %d", &x1,&x2,&x3,&x4,&x5);
		count++;
 	 	b[count].push_back({x1, false});
 	 	b[count].push_back({x2, false});
 	 	b[count].push_back({x3, false});
 	 	b[count].push_back({x4, false});
 	 	b[count].push_back({x5, false});
		if (count == n - 1) {
			game.push_back(b);
			for (int i = 0; i < n; i++)
				b[i].clear();
			count = -1;
		}
	}

	bool winner;
	int gameidx;
	int lastidx;
	vector<bool> winners(game.size());
	fill(begin(winners),end(winners),false);
	for (auto& s : draws) {
		gameidx = 0;
		for (auto& v : game) {
			flipNumber(v,s);
			for (int i = 0; i < n; i++) {
				winner = checkrow(v, i);
				winner = winner ? true : checkcol(v, i); 
				if (winner) {
					winners[gameidx] = true;
				}
			}
			gameidx++;
		}
		if (std::count(begin(winners), end(winners), false) == 1)
		{
			lastidx = std::find(begin(winners), end(winners), false) - winners.begin();
		}
		if (std::count(begin(winners), end(winners), false) == 0)
		{
			int ok = sumBoard(game[lastidx]);
			cout << ok*s << endl;
			return 0;
		}
	}
}

