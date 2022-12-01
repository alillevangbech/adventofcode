#include <algorithm>
#include <bits/stdc++.h>
#include "../util.h"
using namespace std;

int main() {
	std::vector<ll> vec;
	ll tmp = 0;
	string line;
	while (std::getline(std::cin, line))
	{

		if (line == "") {
			vec.push_back(tmp);
			tmp = 0;
		}
		else 
			tmp += std::stoi(line);
	}

	std::sort(vec.begin(), vec.end(), std::greater<>());
	auto res = vec[0] + vec[1] + vec[2];
	std::cout << res << endl;

}
