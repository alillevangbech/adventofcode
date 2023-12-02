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
int flipper(const std::vector<int>& v, const std::vector<int>& h, int x, int y)
{
	int tree = v[x];
	int down = 0, up = 0, right = 0, left = 0;
	for (int i=x; i<v.size(); i++)
	{
		if (v[i] < tree) {
			up++;
			continue;
		}
		up++;
		break;
	}
	for (int i=x; i>=0; i--)
	{
		if (v[i] < tree) {
			down++;
			continue;
		}
		down++;
		break;
	}
	for (int i=y; i<h.size(); i++)
	{
		if (h[i] < tree) {
			left++;
			continue;
		}
		left++;
		break;
	}
	for (int i=y; i>=0; i--)
	{
		if (h[i] < tree) {
			right++;
			continue;
		}
		right++;
		break;
	}
	return down*left*right*up;
}


int main() {
	auto lines = read_input();
	vector<vector<int>> trees;
	vector<int> tmp;
	for (auto s : lines)
	{
		for (auto c : s) {
			tmp.push_back(c - '0');
		}
		trees.push_back(tmp);
		tmp.clear();
	}
	auto t_trees = transpose(trees);
	for (int i=0;i<t_trees.size();i++)
		for (int j=0;i<t_trees[0].size();j++)
			flip





}
