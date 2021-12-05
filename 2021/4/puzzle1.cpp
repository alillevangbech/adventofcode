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

void pGameV2(const allboard& b) {
	for_each(begin(b), end(b), [&](auto& vv)
	{
		for_each(begin(vv),end(vv),[&](auto& v) 
		{
			for_each(begin(v), end(v), [&](auto& e) 
			{
				cout << e.first << ";" << e.second << "\t";
			});
			cout << endl;
		});
	});
}

void pBoard(const board& b) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << b[i][j].first << ";" << b[i][j].second << "\t";
		}
		cout << endl;
	}
}

void flipNumber(board& b, int number)
{
	for_each(begin(b), end(b), [&](auto& v)
	{
		transform(begin(v),end(v),begin(v), [&](auto& row)
		{
			if (row.first == number)
				row.second = true;
			return row;
		});
	});
}

int sumBoard(const board& b) {
	return accumulate(begin(b),end(b),0,
	[](auto lhs, const auto& rhs) 
	{return accumulate(begin(rhs),end(rhs),lhs,
	[](auto lhs1, const auto& rhs1){return lhs1 + (rhs1.second ? 0 : rhs1.first);});});
}

bool checkrow(board& b, int row)
{
	return n == accumulate(begin(b[row]),end(b[row]),0,[](auto lhs, const auto& rhs){return lhs + rhs.second;});
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
	for (auto& s : draws) {
		// cout << s << " ";
		for (auto& v : game) {
			flipNumber(v,s);
//			pGame(game);
//			cout << endl;
			for (int i = 0; i < n; i++) {
				winner = checkrow(v, i);
				winner = winner ? true : checkcol(v, i); 
				if (winner) {
					int sum = sumBoard(v);
					cout << sum*s << endl;
					return 0;
				}
			}
		}
	}
}

