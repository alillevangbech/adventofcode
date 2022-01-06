#include <bits/stdc++.h>
#include <climits>
#include <cstdint>
#include <cstdio>
#include <iterator>
#include "../util.h"
using namespace std;
int main() 
{
	string line;
	string s;
	char c1[10];
	char c;
	map<pair<char,char>,char> rule;
	map<char,ll> poly;

	getline(cin,line);
	for (auto x : line) 
		poly[x]++;
	scanf("");
	while (scanf("%s -> %c\n", c1, &c) != EOF) {
		s = std::string(c1);
		rule[make_pair(s[0],s[1])] = c;
	}

	int steps = 0;
	int maxsteps = 10;
	using rit = map<pair<char,char>,char>::iterator;
	queue<rit> q, qtmp;
	for (auto it = line.begin(); it + 1 != line.end(); it++)
	{
		rit ruleiter = rule.find(make_pair(*it,*(it+1)));
		if (ruleiter != rule.end())
			q.push(ruleiter);
	}
	rit it,it1,it2;
	while (steps < maxsteps) {
		while (!q.empty()) {
			rit it = q.front();
			q.pop();
			poly[it->second]++;
			
			it1 = rule.find(make_pair(it->first.first, it->second));
			if (it1 != rule.end()) {
				qtmp.push(it1);
			}

			it2 = rule.find(make_pair(it->second, it->first.second));
			if (it2 != rule.end()) {
				qtmp.push(it2);
			}
		}
		q.swap(qtmp);
		steps++;
	}
	ll max = 0, min = INT_MAX;
	for (auto x : poly) {
		max = std::max(max, x.second);
		min = std::min(min, x.second);
	}
	cout << max - min << endl;
	return 0;
}
