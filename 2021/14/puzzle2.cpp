#include <bits/stdc++.h>
#include <climits>
#include <cstdint>
#include <cstdio>
#include <iterator>
#include <tuple>
#include <utility>
#include "../util.h"
using namespace std;
using polymer = map<char,ll>;
using rules = map<pair<char,char>,char>;
using rit = rules::iterator;
static map<tuple<char,char,int>,polymer> cache;


void addpolymer(polymer& p1, const polymer& p2)
{
	for (auto x : p2) {
		p1[x.first] += x.second;
	}
}

polymer fv2(char common, char pad, bool left, rules &rule, int step, int stepmax) {
	pair<char,char> p = left ? make_pair(pad,common) : make_pair(common,pad);
	polymer pp,p1,p2;
	tuple<char,char,int> t1,t2;
	rit it = rule.find(p);
	if (step == stepmax || it == rule.end()) {
		// We are at a leaf;
		return pp;
	}

	step++;
	pp[it->second]++;
	//cout << it->second;

	// Deepdive left;
	t1 = make_tuple(it->first.first, it->second, stepmax - step);
	if (cache.find(t1) != cache.end()) {
		p1 = cache[t1];
	} else { 
		p1 = fv2(it->second, it->first.first, true, rule, step, stepmax);
		cache[t1] = p1;
	}

	// Deepdive right;
	t2 = make_tuple(it->second, it->first.second, stepmax - step);
	if (cache.find(t2) != cache.end()) {
		p2 = cache[t2];
	} else { 
		p2 = fv2(it->second, it->first.second, false, rule, step, stepmax);
		cache[t2] = p2;
	}
	

	addpolymer(pp, p1);
	addpolymer(pp, p2);
	return pp;
	// Save results;
};

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
	int maxsteps = 40;
	for (auto it = line.begin(); it + 1 != line.end(); it++) {
		addpolymer(poly, fv2(*it, *(it+1), false, rule, steps, maxsteps));
	}
		
	ll max = 0, min = INT64_MAX;
	for (auto x : poly) {
		max = std::max(max, x.second);
		min = std::min(min, x.second);
	}
	cout << max-min << endl;
	return 0;
}
