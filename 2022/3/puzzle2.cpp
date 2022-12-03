#include <algorithm>
#include <tuple>
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
	std::vector<std::tuple<string, string, string>> vec;
	while (std::getline(std::cin, line)) {
		auto s1 = line;
		std::getline(std::cin, line);
		auto s2 = line;
		std::getline(std::cin, line);
		auto s3 = line;
		vec.push_back(make_tuple(s1,s2,s3));
	}

	ll sum = 0;
	for (auto [s1,s2,s3] : vec) {
		for (auto c : s1)
		{
			if (s2.find_first_of(c) != std::string::npos && s3.find_first_of(c) != std::string::npos) {
				sum += prio(c);
				break;
			}
		}
	}
	cout << sum << endl;
	return 0;
}
