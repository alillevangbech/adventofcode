
#ifndef __UTILS_H__
#define __UTILS_H__

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;
typedef std::unordered_map<int,int> numbermap;

vector<int> loaddata(string s)
{
	vector<int> v;
	stringstream ss(s);
	while(getline(ss,s,','))
	{
		v.push_back(std::stoi(s));
	}
	return v;
}

int playturns(vector<int> startnumbers, int turns)
{
	numbermap dict;
	int turn = 1;
	int spoken_number = 0;
	int temp = 0;
	for (int e : startnumbers)
	{
		if (dict.find(e) == dict.end())
		{
			dict[e] = turn;
			spoken_number = 0;
		}
		else
		{
			spoken_number = turn - dict[e];
			dict[e] = turn;
		}
		//cout << turn << ": " << spoken_number << endl;
		turn++;
	}

	while (turn < turns)
	{
		if (dict.find(spoken_number) == dict.end())
		{
			dict[spoken_number] = turn;
			spoken_number = 0;
			//cout << turn << ": " << spoken_number << "not found " << endl;
		}
		else
		{
			temp = turn - dict[spoken_number];
			dict[spoken_number] = turn;
			spoken_number = temp;
			//cout << turn << ": " << spoken_number << " found" << endl;
		}
		turn++;
	}

	return spoken_number;
}

#endif


