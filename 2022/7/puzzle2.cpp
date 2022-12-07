#include <algorithm>
#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <numeric>
#include <ranges>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include "../util.h"
using namespace std;
namespace rv = std::ranges::views;
namespace sv = std::views;
#define ATMOST 10000000000
#define REQUIRED_SIZE 30000000
#define TOTAL_SIZE 70000000

struct file {
	file(string _name, ll _size)
	{
		name = _name;
		size = _size;
	}
	ll size;
	string name;
};
struct dir {
	public:
	dir(string _name, dir* _root)
	{
		name = _name;
		root = _root;
	}
	string name;
	vector<file> files;
	vector<dir*> dirs;
	dir* root;
	ll size() {ll sum = 0; for (auto x : files) sum += x.size; return sum;};
};
dir* trav(dir* cur, string s);
dir* cd(dir* cur, string s){
	if (s == "/") {
		while (cur->root != NULL) cur = cur->root;
		return cur;
	} else if (s == "..") {
		if (cur->root != NULL) cur = cur->root;
		return cur;
	} else {
		return trav(cur,s);
	}
}
dir* trav(dir* cur, string s){
	for (auto d : cur->dirs) {
		if (d->name == s) return d;
	}
	return cur->name == s ? cur : NULL;
}
ll trav_atmost(dir* cur){
	ll size = cur->size();
	for (auto d : cur->dirs) {
		size += trav_atmost(d);
	}
	ll s = size;
	return s;
}

ll trav_total(dir* cur, ll* total, ll outer_total){
	ll size = cur->size();
	for (auto d : cur->dirs) {
		size += trav_total(d, total, outer_total);
	}
	ll s = size;
	ll total_deleted_size = TOTAL_SIZE - outer_total + s;
	cout << total_deleted_size <<  "|" << s << "|" << (total_deleted_size > REQUIRED_SIZE) << endl;
	if (total_deleted_size >= REQUIRED_SIZE && s < *total) {
		*total = s;
	}
	return s;
}

int main() {
	auto lines = read_input();
	dir* root = new dir("/", NULL); 
	string tmp;
	for (auto x : lines)
	{
		// cmd
		auto first = x.find_first_of(' '), last = x.find_last_of(' ');
		string s1, s2;
		if (x[0] == '$') {
			if (last != first) {
				s2 = x.substr(last+1);
				root = cd(root, s2);
			}
		} else {
			s1 = x.substr(0, first);
			s2 = x.substr(first+1);
			if (s1 == "dir") {
				root->dirs.push_back(new dir(s2, root));
			} else {
				root->files.push_back(file(s2, std::stoll(s1)));
			}
		}
	}
	root = cd(root, "/");
	cout << root->name << endl;
	ll* total = new ll(ATMOST);
	ll t = trav_atmost(root);
	ll text = trav_total(root, total, t);
	cout << *total << endl;
}
