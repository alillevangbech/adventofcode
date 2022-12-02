#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <numeric>
#include <ranges>
#include <unordered_map>
#include "../util.h"

#define DRAW 3
#define LOSE 0
#define WIN  6

#define ROCK  1
#define PAPER  2
#define SCISSORS  3

ll score(char x, char y)
{

	if (x == 'A') {
		if (y == 'X') return ROCK + DRAW;
		else if (y == 'Y') return PAPER + WIN;
		else if (y == 'Z') return SCISSORS + LOSE;
	}
	if (x == 'B')
		if (y == 'X') return ROCK + LOSE;
		else if (y == 'Y') return PAPER + DRAW;
		else if (y == 'Z') return SCISSORS + WIN;

	if (x == 'C')
		if (y == 'X') return ROCK + WIN;
		else if (y == 'Y') return PAPER + LOSE;
		else if (y == 'Z') return SCISSORS + DRAW;

	return 1000000;
}

int main() {
	std::string line;
	std::vector<ll> vec;
	while (std::getline(std::cin, line)) {
		vec.push_back(score(line[0], line[2]));
	}

	std::cout << std::accumulate(vec.begin(), vec.end(), 0, std::plus<ll>()) << std::endl;
	return 0;
}
