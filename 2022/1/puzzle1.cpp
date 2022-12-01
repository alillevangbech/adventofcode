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

	std::cout << *max_element(vec.begin(), vec.end()) << std::endl;


}
