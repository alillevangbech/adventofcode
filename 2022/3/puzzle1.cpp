#include <algorithm>
#include <vector>
#include <string>
#include <ctype.h>
#include <iostream>
#include <math.h>
#include <numeric>
#include <ranges>
#include <unordered_map>
#include "../util.h"
using namespace std;
ll prio(char c) { return isupper(c) ? c - '0' + 10 : c - '0' - 48;}

int main() {
	std::string line;
	std::vector<std::string> vec;
	while (std::getline(std::cin, line)) {
		vec.push_back(line);
	}

	ll sum = 0;
	for (auto s : vec) {
		auto split = s.size() / 2;
		string s1 = s.substr(0, split);
		string s2 = s.substr(split);

		for (auto c : s1)
		{
			if (s2.find_first_of(c) != std::string::npos) {
				sum += prio(c);
				break;
			}
		}
	}
	cout << sum << endl;
	return 0;
}
