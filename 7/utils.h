
#ifndef __UTILS_H__
#define __UTILS_H__

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct bag
{
	std::string m_name; bool isVisited;
	std::unordered_map<std::string,int> m_map;
};

bag parseBag(std::string s)
{
	bag b; 
	b.m_name = s.substr(0,s.find("bag") -1);
	std::string cont = "contain ";
	cont = s.substr(s.find(cont) + cont.length());
	istringstream ss(cont);
	size_t split = 0;
	while (getline(ss,s,','))
	{	
		if (s == "no other bags.") continue;
		if (s[0] == ' ') s.erase(0,1);
		split = s.find(' ');
		int number = std::stoi(s.substr(0,split));
		s.erase(0,split+1);
		string name = s.substr(0,s.find_last_of(' '));
		b.m_map[name] = number;
	}
	return b;
}

int findBag(const vector<bag>& allBags, const string& targetBagName)
{
	for (int i = 0; i < allBags.size(); i++)
	{
		if (allBags[i].m_name == targetBagName) return i;
	}
	return -1;
}

bool searchBag(const vector<bag>& allBags, const bag& startBag, const std::string& targetBagName)
{
	if (startBag.m_name == targetBagName) return true;
	int index = -1;
	int success = 0;
	for (std::pair<std::string,int> innerBag : startBag.m_map)
	{
		index = findBag(allBags,innerBag.first);
		if (index == -1) continue;
		success += searchBag(allBags,allBags[index],targetBagName);
	}
	return success > 0;
}

long countBag(const vector<bag>& allBags, const bag& startBag, const string& name)
{
	long sum = 1;
	int index = 0;

	for (std::pair<std::string,int> innerBag : startBag.m_map)
	{
		index = findBag(allBags,innerBag.first);
		sum += innerBag.second*countBag(allBags, allBags[index], name);
	}
	//cout << startBag.name << ": " << sum << endl;
	return sum;
}


#endif


