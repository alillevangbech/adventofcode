#include <algorithm>
#include <cstring>
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
using rock = vector<string>;

#define ROCKNUMBER 2022
#define CHAMBER_WIDTH 7
#define EMPTY '.'
#define SETTLED '#'
#define ROCK '@'



void print_rock(const rock& r)
{
	for (auto rr : r)
		cout << rr << endl;
}

void print_floor(const deque<string>& r)
{
	for (auto x = 0; x < r.size(); x++)
		cout << r[x] << "|" << x << endl;
	cout <<	string(CHAMBER_WIDTH, '_') << endl;
}

void print_rock_floor_concat(const deque<string>& floor, const rock& r)
{
	print_rock(r);
	print_floor(floor);
}

void rotate_rock(const deque<string>& floor, rock& r, int floor_idx,  char c)
{
	// what is it_floor - the place where the end of rock points to.
	
	//       	  ...@...	
	//       	  ..@@@..
	//            ...@...	 0
	// .......	  .......	 1-> it_floor // loop over rock, and go backwards, until we hit floor.begin()
	// .......	  .......	 2
	// .......	  .......	 3
	// ..#....    ..#....    4
	// ..#....    ..#....    5
	// .#####.    .#####.    6
	
	bool canrotate = true;
	for (auto it = r.rbegin(); it != r.rend(); it++)
	{
		if (floor_idx == -1 || !canrotate)
			break;

		auto rockstring = *it;
		auto floorstring = floor[floor_idx];

		auto first = rockstring.find_first_of(ROCK);
		auto last = rockstring.find_last_of(ROCK);

		if (canrotate && c == '<')
			canrotate = !(first != std::string::npos && first != 0 && floorstring[first-1] == SETTLED);

		if (canrotate && c == '>')
			canrotate = !(last != std::string::npos && last != rockstring.size()-1 && floorstring[last+1] == SETTLED);
		// assume string doesnt overlap 
		floor_idx--;
	}

	//cout << canrotate << test << endl;
	if (!canrotate)
		return;

	if (c == '<') {
		for_each(r.begin(), r.end(), [&](string& s) {if (canrotate) canrotate = s.front() != ROCK;}); // do i hit walls
		if (canrotate) {
			for_each(r.begin(), r.end(), [&](string& s) {std::rotate(s.begin(), s.begin()+1, s.end());});
		}
	} else if (c == '>') {
		for_each(r.begin(), r.end(), [&](string& s) {if (canrotate) canrotate = s.back() != ROCK;});
		if (canrotate)
			for_each(r.begin(), r.end(), [&](string& s) {std::rotate(s.rbegin(), s.rbegin()+1, s.rend());});
	}
}

// ptr to btm of floor
bool match_and_merge(deque<string>& floor, rock& r, int floor_idx)
{
	bool match = false;
	
	bool lastfloor = floor_idx == floor.size() -1 && floor[floor_idx].find(SETTLED) == std::string::npos;
	if (lastfloor)
		return false;
	match = floor_idx == floor.size();
	
	while (!(floor_idx == -1 || match)) {
		for (auto x = r.rbegin(); x != r.rend(); x++) {
			// do i match
			auto rockstring = *x;
			auto floorstring = floor[floor_idx];
			cout << floorstring << endl;

			for (int i=0;i<rockstring.size();i++) {
				match = !match ? rockstring[i] == ROCK && floorstring[i] == SETTLED : match;
			}
		}
		floor_idx--;	
	}


	// insert into floor
	if (match) {
		floor_idx -= floor_idx == floor.size();

		for (auto x = r.rbegin(); x != r.rend(); x++) {
			
			for (int i=0;i<floor[floor_idx].size();i++) {
				cout << *x << "||" << floor[floor_idx] << endl;
				floor[floor_idx][i] = (*x)[i] == ROCK ? SETTLED : floor[floor_idx][i];
			}

			floor_idx--;
		}
	}

	return match;
}

void add_layers(deque<string>& floor)
{
	// find first non empty layer
	int j = -1;
	for (int i=0;i<floor.size();i++)
	{
		// found settled
		if (floor[i].find_first_of(SETTLED) != std::string::npos) {
			j = i;
			break;
		}
	}
	if (j == -1)
		j = floor.size();
	
	for (int i=j+1;i<=3;i++)
		floor.push_front(string(CHAMBER_WIDTH, '.'));
}

int main() {
	auto dir = read_input()[0];
	deque<string> floor;
	deque<rock> rocks;
	rocks.push_back(rock{"..@@@@."});
	rocks.push_back(rock{"...@...", "..@@@..","...@..."});
	rocks.push_back(rock{"....@..", "....@..","..@@@.."});
	rocks.push_back(rock{"..@....", "..@....","..@....","..@...."});
	rocks.push_back(rock{"..@@...", "..@@..."});
	auto prock = rocks.begin();
	auto pdir = dir.begin();
	
	cout << dir << endl;
	for (int i=0;i<ROCKNUMBER;i++){
		cout << "NUMBER: " << i << endl;
	//	print_rock(*prock);
		// have to cpy rock
		rock tmprock = *prock;
		add_layers(floor);
		//print_rock_floor_concat(floor, tmprock);
		
		// add layers
		// rotate rock
		// match floor with floor
		for (int ptr = 0; ptr <= (int)floor.size(); ptr++)
		{
			cout << *pdir << "|" << ptr << "|" << floor.size() << "| already rotated for this floor" << endl;
			rotate_rock(floor, tmprock, ptr - 1, *pdir);
			cout << *pdir << "|" << ptr << "|" << floor.size() << "| already rotated for this floor" << endl;
			if (match_and_merge(floor, tmprock, ptr))
				break;

			pdir = pdir == dir.end() - 1 ? dir.begin() : pdir + 1;
			print_rock_floor_concat(floor, tmprock);
		}

		print_floor(floor);
		pdir = pdir == dir.end() - 1 ? dir.begin() : pdir + 1;
		prock = prock == rocks.end() - 1 ? rocks.begin() : prock + 1;
	}
}
