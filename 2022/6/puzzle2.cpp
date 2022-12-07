#include <iterator>
#include <vector>
#include <string>
#include <iostream>
#include <ranges>
#include <math.h>
#include <numeric>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include "../util.h"
using namespace std;
namespace rv = std::ranges::views;
namespace sv = std::views;
bool brute(deque<char> c) {
	unordered_set<char> s = unordered_set(c.begin(), c.end());
	return s.size() == 14;
}

int main() {
	auto lines = read_input();
	unordered_map<char, int> m;
	deque<char> q;
	int idx;
	char c;
	bool recmarker = false;
	for (idx = 0; idx <lines[0].size(); idx++)
	{
		c = lines[0][idx];
		m[c]++;
		q.push_back(c);
		if (!recmarker)
			recmarker = m[c] >= 2;

		if (idx >= 13) {
			if (recmarker && brute(q)) {
				break;
			}
			q.pop_front();
		}

	}
	idx++;
	cout << idx << endl;
}
