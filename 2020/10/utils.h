
#ifndef __UTILS_H__
#define __UTILS_H__


#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> loaddata()
{
	ifstream ifile("./input.txt");
	string line;
	vector<int> res;
	while (getline(ifile,line)) res.push_back(std::stoi(line));
	return res;
}

int algo1(vector<int>& holder)
{
	int jolt1 = 0;
	int jolt3 = 0;
	int cur = 0;
	int diff = 0;
	std::sort(holder.begin(),holder.end(), [](int a, int b) { return a < b; });
	for (int el : holder)
	{
		diff = el - cur;
		if (diff == 1) jolt1++;
		if (diff == 3) jolt3++;
		cur += diff;
	}
	jolt3++;

	return jolt1*jolt3;
}

long algo2(vector<int>& holder)
{
	std::sort(holder.begin(),holder.end(), [](int a, int b) { return a < b; });
	holder.erase(std::unique(holder.begin(),holder.end()),holder.end());
	vector<long> nodevals (holder.size(),0);
	nodevals.front()++;
	int cur = 0;
	int idx = 0;
	auto reachable = [](int cur, int target) { return cur + 3 >= target; };
	for (int i = 0; i < holder.size(); i++)
	{
		cur = holder[i];
		idx = i + 1;
		while (idx < holder.size() && idx < i + 4)
		{
			nodevals[idx] += reachable(cur,holder[idx]) ? nodevals[i] : 0;
			idx++;
		}
	}

	return nodevals.back();
}

#endif


