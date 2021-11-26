
#ifndef __UTILS_H__
#define __UTILS_H__


#include <vector>
#include <sstream>
#include <string>
#include <iostream>
using namespace std;

void split_into_vector(vector<string>& vec, std::string s, char split)
{
	std::istringstream ss(s);
	while (std::getline(ss,s,split))
	{
		if (s != "")
		{
			vec.push_back(s);
		}
	}
}

void simple_split_vector(vector<string>& vec, std::string s, char split)
{
	std::string holder;
	std::istringstream ss(s);
	while (std::getline(ss,s,split))
	{
		if (s != "")
		{
			holder += s;
		}
	}
	vec.push_back(holder);
}

string alphabet()
{
	std::string ret;
	for (int i = 0; i < 26; i++)
	{
		ret += (char)((int)'a' + i);
	}

	return ret;
}

void reset_vector(std::vector<bool>& vec)
{
	for (auto i = vec.begin(); i != vec.end(); i++) *i = false;
}

void reset_vector(std::vector<int>& vec)
{
	for (auto i = vec.begin(); i != vec.end(); i++) *i = 0;
}

int count_vector(const std::vector<bool>& vec)
{
	int res = 0;
	for (auto i = vec.begin(); i != vec.end(); i++) if ((*i)) res++;
	return res;
}

int count_vector(const std::vector<int>& vec, int matcher)
{
	int res = 0;
	for (auto i = vec.begin(); i != vec.end(); i++) if (*i == matcher) res++;
	return res;
}

void print_vector(const std::vector<bool>& vec)
{
	for (auto i = vec.begin(); i != vec.end(); i++) std::cout << *i;
}

void print_vector(const std::vector<int>& vec)
{
	for (auto i = vec.begin(); i != vec.end(); i++) std::cout << *i;
}

#endif


