
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

vector<int> loaddata()
{
	ifstream ifile ("./input.txt");
	string line;
	vector<int> holder;
	getline(ifile,line);
	holder.push_back(std::stoi(line));
	while (getline(ifile,line,','))
	{
		if(line[0] != 'x') holder.push_back(std::stoi(line));
	}
	return holder;
}


map<int,int> loaddata2()
{
	ifstream ifile ("./input.txt");
	string line;
	map<int,int> holder;
	getline(ifile,line);
	int count = 0;
	while (getline(ifile,line,','))
	{
		if (line[0] == 'x') count++;
		else
		{
			holder[(std::stoi(line))] = count;
			count++;
		}
	}
	return holder;
}

bool testTimestamp2(map<int,int> map, long timestamp)
{
	for (auto el : map)
	{
		if (el.second == 0 && (timestamp % el.first) != 0)
		{
			return false;
		}
		else if (el.second == 0) continue;
		if ((el.first - (timestamp % el.first)) != el.second) return false;
	}
	return true;
}
#endif

