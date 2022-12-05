#include <algorithm>
#include <iomanip>
#include <iterator>
#include <stdio.h>
#include <vector>
#include <string>
#include <ctype.h>
#include <iostream>
#include <math.h>
#include <numeric>
#include <ranges>
#include <stack>
#include <queue>
#include <unordered_map>
#include "../util.h"
#define LEN 9
using namespace std;
namespace rv = std::ranges::views;
namespace sv = std::views;
void parse(int idx, string s, vector<stack<char>>& crates, int cidx) {
	if (s[idx] != ' ')
		crates[cidx].push(s[idx]);
} 

int main() {
	auto lines = read_input();
	vector<stack<char>> crates;
	vector<string> rev;
	for (int j=0;j<LEN+1;j++)
		crates.push_back(stack<char>{});

	int i = 0;
	while (lines[i][1] != '1') {
		rev.push_back(lines[i]);
		i++;
	}
	
	int col = 0;
	for (auto s : rev | rv::reverse) {
		for (int j=1;j<s.size();j+=4) {
			col++;
			parse(j, s, crates, col); 
		}
		col = 0;
	}

	i += 2;

	for (;i<lines.size();i++){
		int e1,e2,e3;
		char crate;
		sscanf(lines[i].c_str(), "move %d from %d to %d\n", &e1,&e2,&e3);
		for (int q=0;q<e1;q++) {
			crate = crates[e2].top();
			crates[e2].pop();
			crates[e3].push(crate);
		}
	}
	for (int q=1;q<LEN+1;q++)
		cout << (crates[q].size() != 0 ? crates[q].top() : '-');
	cout << endl;
}
