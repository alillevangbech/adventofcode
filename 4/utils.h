
#ifndef __UTILS_H__
#define __UTILS_H__

#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <sstream>
#include <iostream>
void split_into_vector(std::map<std::string,std::string>& map, std::string s, char c1, char c2)
{
	std::replace(s.begin(),s.end(),c1,c2);
	std::istringstream ss(s);
	while (std::getline(ss,s,c2))
	{
		if (s != "")
		{
			size_t k = s.find(':');
			map[s.substr(0,k)] = s.substr(k+1);
		}
	}
}

void reset_vector(std::vector<bool>& vec)
{
	for (auto i = vec.begin(); i != vec.end(); i++) *i = false;
}

bool check_vector(const std::vector<bool>& vec)
{
	for (auto i = vec.begin(); i != vec.end(); i++) if (!(*i)) return false;
	return true;
}

void print_vector(const std::vector<bool>& vec)
{
	for (auto i = vec.begin(); i != vec.end(); i++) std::cout << *i;
}

#endif


