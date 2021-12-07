#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include "../util.h"
using namespace std;
int mean(const vector<int>& v)
{
	return std::reduce(begin(v),end(v)) / v.size();
}

int main() 
{
	int x, res, sum = 0;
	vector<int> v;
	while (cin >> x) {
		v.push_back(x);
	}
	res = mean(v);
	for (auto i : v) {
		int n = abs(i - res);
		sum += (n*(n+1))/2;
	}
	cout << sum << endl;
	return 0;
}
