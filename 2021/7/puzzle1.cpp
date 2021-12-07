#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include "../util.h"
using namespace std;
int median(vector<int> v)
{
	int res;
	sort(begin(v),end(v));
	if (v.size() % 2 == 0)
		res = (v[v.size()/2 - 1] + v[v.size()/2])/2;
	else
		res = v[v.size()/2];
	return res;
}

int main() 
{
	int x, res, sum = 0;
	vector<int> v;
	while (cin >> x) {
		v.push_back(x);
	}
	res = median(v);
	for (auto i : v) {
		sum += abs(i - res);
	}
	cout << sum << endl;
	return 0;
}
