#include <algorithm>
#include <stdio.h>
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
using elf = std::tuple<int,int,int,int>;

int main() {
	std::string line;
	std::vector<elf> vec;
	while (std::getline(std::cin, line)) {
		int e1, e2, e3, e4;
		sscanf(line.c_str(), "%d-%d,%d-%d", &e1,&e2,&e3,&e4); 
		vec.push_back(tie(e1,e2,e3,e4));
	}
	int overlap = 0;
	for (auto [e1,e2,e3,e4] : vec) 
	{
		overlap += (e1 <= e3 && e3 <= e2) ||
				  (e1 <= e4 && e4 <= e2) ||
				  (e3 <= e1 && e1 <= e4) ||
				  (e3 <= e2 && e2 <= e4);
	}
	cout << overlap << endl;
}
