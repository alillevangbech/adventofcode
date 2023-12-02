#include <algorithm>
#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <numeric>
#include <ranges>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include "../util.h"
using namespace std;
namespace rv = std::ranges::views;
namespace sv = std::views;
void flipper(const std::vector<int>& v, std::vector<bool>& flip)
{
	for (auto x : v) {
		cout << x;
	}
	cout << endl;

	for (auto x : flip) {
		cout << x;
	}
	cout << endl;

	int start = -1;
	//cout << start << endl;
	for (int i=0;i<v.size();i++) {
		if (v[i] > start) {
			flip[i] = true;
			start = v[i];
		}
	}

	for (auto x : flip) {
		cout << x;
	}
	cout << endl;

	start = -1;
	for (int i=v.size()-1;i>=0;i--) {
		if (v[i] > start) {
			flip[i] = true;
			start = v[i];
		}
	}

	for (auto x : flip) {
		cout << x;
	}
	cout << endl;
	cout << "\n";

	
}
int main() {
	auto lines = read_input();
	vector<vector<int>> trees;
	vector<vector<bool>> insight;
	vector<int> tmp;
	vector<bool> btmp;
	for (auto s : lines)
	{
		for (auto c : s) {
			tmp.push_back(c - '0');
			btmp.push_back(false);
		}
		trees.push_back(tmp);
		insight.push_back(btmp);
		tmp.clear();
		btmp.clear();
	}
	for (int i=0;i<trees.size();i++)
		flipper(trees[i], insight[i]);
	auto t_insight = transpose(insight);
	auto t_trees = transpose(trees);
	for (int i=0;i<t_trees.size();i++)
		flipper(t_trees[i], t_insight[i]);
	ll sum = 0;
	//for (auto v : t_trees) {
	//	for (auto x : v) {
	//		cout << x; 
	//	}
	//	cout << endl;
	//}
	for (auto v : t_insight)
		sum += accumulate(v.begin(), v.end(), 0, [&](ll sum, bool b) {return sum + b;});
	cout << sum;

	























	












}
