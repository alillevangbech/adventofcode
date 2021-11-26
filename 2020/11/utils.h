
#ifndef __UTILS_H__
#define __UTILS_H__


#include <exception>
#include <stdexcept>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

vector<vector<char>> loaddata()
{
	ifstream ifile("./input.txt");
	string line;
	vector<vector<char>> holder;
	while (getline(ifile,line)) holder.push_back(vector<char>(line.begin(),line.end()));
	return holder;
}

void simulateround(vector<vector<char>>& map)
{
	int adjseats;
	int adjvisibleseats;
	auto newmap(map);
	
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size(); j++)
		{
			adjseats = 0;
			adjvisibleseats = 0;
			for (int x = -1; x < 2; x++)
			{
				for (int y = -1; y < 2; y++)
				{
					if (y == 0 && x == 0) continue;
					try
					{
						adjseats += map.at(i+x).at(j+y) == '#';
					}
					catch (std::exception a)
					{
					}
				
				}
			}
			if (adjseats == 0 && map[i][j] == 'L') newmap[i][j] = '#';
			if (map[i][j] == '#' && adjseats >= 4) newmap[i][j] = 'L';
		}

	}
	map = newmap;
}


bool adjseat(vector<vector<char>>& map, int y, int x)
{
	try
	{
		return map.at(y).at(x) == '#';
	}
	catch (std::exception a)
	{
	}
	return false;
}


/*	
 * occ seat;
 *	- look into every dir
 *
 *
 *
 */


bool adjvisibleseat(vector<vector<char>>& map, int y_dir, int x_dir, int y_place, int x_place, char seat)
{
	x_place += x_dir;
	y_place += y_dir;
	while (true)
	{
	try
	{	
		if (map.at(y_place).at(x_place) == seat) return true;
		x_place += x_dir;
		y_place += y_dir;
	}
	catch (std::out_of_range a)
	{
		return false;
	}
	}
}

bool adjvisibleseatocc(vector<vector<char>>& map, int y_dir, int x_dir, int y_place, int x_place)
{
	char c;
	x_place += x_dir;
	y_place += y_dir;
	while (true)
	{
	try
	{	
		c = map.at(y_place).at(x_place);
		if (c == '#') return true;
		if (c == 'L') return false;
		x_place += x_dir;
		y_place += y_dir;
	}
	catch (std::out_of_range a)
	{
		return false;
	}
	}
}


void simulateround2(vector<vector<char>>& map)
{
	int adjseats;
	int adjvisibleseatsocc;
	auto newmap(map);
	
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size(); j++)
		{
			adjseats = 0;
			adjvisibleseatsocc = 0;
			for (int y = -1; y < 2; y++)
			{
				for (int x = -1; x < 2; x++)
				{
					if (y == 0 && x == 0) continue;
					adjseats += adjseat(map,i+y,j+x);
					adjvisibleseatsocc += adjvisibleseatocc(map,y,x,i,j);
				}
			}
			if (adjvisibleseatsocc == 0 && map[i][j] == 'L') newmap[i][j] = '#';
			if (map[i][j] == '#' && adjvisibleseatsocc >= 5) newmap[i][j] = 'L';
		}
	}
	map = newmap;
}

int countfast(const vector<vector<char>>& map)
{
	int count_occupied = 0;
	for (auto el : map)
		count_occupied += std::count(el.begin(),el.end(),'#');
	return count_occupied;
}

void printmap(vector<vector<char>>& map)
{
	for (auto e : map)
	{
		for (auto a : e)
			cout << a;
		cout << endl;
	}
	cout << endl;
}

int convergeandcount(vector<vector<char>>& map)
{
	int count_occupied = 1;
	int count_prev = 0;
	while (count_prev != count_occupied)
	{
		count_prev = count_occupied;
		simulateround(map);
		count_occupied = countfast(map);
	}
	return count_occupied;
}

int convergeandcount2(vector<vector<char>>& map)
{
	int count_occupied = 1;
	int count_prev = 0;
	while (count_prev != count_occupied)
	{
		count_prev = count_occupied;
		simulateround2(map);
		count_occupied = countfast(map);
	}
	return count_occupied;
}

#endif

