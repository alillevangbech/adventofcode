
#ifndef __UTILS_H__
#define __UTILS_H__

void placeholder(); 

#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

long getXMASResult(const vector<long>& holder, int preamble)
{
	std::deque<long> runner;
	size_t idx = 0;
	bool visited;
	for (const long element : holder)
	{
		if (idx < preamble) {runner.push_back(element); idx++; continue;}
		
		visited = false;
		for (size_t i = 0; i < runner.size(); i++)
		{
			for (size_t j = i; j < runner.size(); j++)
			{
				if (runner[i] + runner[j] == element) visited = true;
			}
		}
			
		if (!visited) return element;

		runner.pop_front();
		runner.push_back(element);
		idx++;
	}

	return -1;
}

long getXMASWeakness(const vector<long>& holder, int preamble)
{
	long XMASResult = getXMASResult(holder,preamble);
	long test;
		
	for (size_t i = 0; i < holder.size(); i++)
	{
		test = holder[i];
		for (size_t j = i + 1; j < holder.size(); j++)
		{	
			test += holder[j];
			if (test == XMASResult)
			{
				std::cout << i << ": " << j << endl;
				auto b = holder.begin() + i;
				auto e = holder.begin() + j;
				return *max_element(b,e) + *min_element(b,e);
			}
		}
	}
			
	return -1;
}
#endif


