#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>
#include <unordered_map>
#include "../util.h"
using namespace std;
typedef vector<vector<char>> paper;
int count_dots(vector<vector<char>>& map); 
vector<char> mergex(vector<char>& v, int idx) {
	vector<char> vq;
	for (int i = 0, j = v.size() -1; i < idx && idx < j; i++, j--) {
		vq.push_back(v[i] == '#' || v[j] == '#' ? '#' : '.');
	}
	return vq;
} 
vector<char> mergey(vector<char>& v1, vector<char>& v2) {
	vector<char> vq;
	for (int i = 0; i < v2.size(); i++)
		vq.push_back(v1[i] == '#' || v2[i] == '#' ? '#' : '.');
	return vq;
}

void foldx(paper& map, int idx) {
	for (auto& xvec : map) {
		xvec = move(mergex(xvec,idx));
	}
}
void foldy(paper& map, int idx) {
	paper newmap;
	for (int i = 0, j = map.size() - 1; i < idx || idx < j; i++, j--) {
		newmap.push_back(mergey(map[i], map[j]));
	}
	map.swap(newmap);
}

void p(paper& map); 
int main() 
{
	string line;
	vector<pair<int,int>> dots;
	vector<pair<char,int>> folds;
	int x,y,z;
	char c;
	while (getline(cin,line))
	{
		if (line[0] == 'x' || line[0] == 'y') {
			sscanf(line.c_str(), "%c %d", &c,&z);
			folds.push_back({c,z});
		} else {
			sscanf(line.c_str(), "%d %d", &x,&y);
			dots.push_back({x,y});
		}
	}
	auto pxn = max_element(begin(dots), end(dots), [](const auto& p1, const auto& p2){return p1.first < p2.first;});
	auto pyn = max_element(begin(dots), end(dots), [](const auto& p1, const auto& p2){return p1.second < p2.second;});
	const int xn = pxn->first;
	const int yn = pyn->second;
	vector<vector<char>> map (yn+2, vector<char>(xn+1,'.'));
	for (auto xy : dots) {
		map[xy.second][xy.first] = '#';
	}
	int count = 0;
	for (auto xy : folds) {
		count++;
		if (xy.first == 'x') {
			foldx(map, xy.second);
		} else {
			foldy(map, xy.second);
		}
		cout << count_dots(map) << endl;
		break;
	}

	return 0;
}

void p(vector<vector<char>>& map) 
{
	for (auto v : map) {
		for (auto vv : v) {
			cout << vv;
		}
		cout << endl;
	}
	cout << endl;
}

int count_dots(vector<vector<char>>& map) 
{
	int count = 0;
	for (auto v : map) {
		for (auto vv : v) {
			count += vv == '#';
		}
	}
	return count;
}
/*
*/
