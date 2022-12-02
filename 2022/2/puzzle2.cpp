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

ll scorev2(char x, char y)
{
	if (x == 'A') {
		if (y == 'X') return LOSE + SCISSORS;
		else if (y == 'Y') return DRAW + ROCK;
		else if (y == 'Z') return WIN + PAPER;
	}
	if (x == 'B')
		if (y == 'X') return LOSE + ROCK;
		else if (y == 'Y') return DRAW + PAPER;
		else if (y == 'Z') return WIN + SCISSORS;

	if (x == 'C')
		if (y == 'X') return LOSE + PAPER;
		else if (y == 'Y') return DRAW + SCISSORS;
		else if (y == 'Z') return WIN + ROCK;

	return 1000000;
}

int main() {
	std::string line;
	std::vector<ll> vec;
	while (std::getline(std::cin, line)) {
		vec.push_back(scorev2(line[0], line[2]));
	}

	std::cout << std::accumulate(vec.begin(), vec.end(), 0, std::plus<ll>()) << std::endl;
	return 0;
}
