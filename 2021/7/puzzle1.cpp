#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include "../util.h"
using namespace std;
int main() 
{
	int x;
	vector<int> v;
	while (cin >> x) {
		v.push_back(x);
	}
	int max = *max_element(begin(v),end(v));
	int min = *min_element(begin(v),end(v));
	unordered_map<int, int> umap;
	// int middle = (max - min);
	for (int i = min; i <= max; i++)
	{
		// cout << i << ": ";
		for (auto r : v) {
			// cout << abs(r-i) << " ";
			umap[i] += abs(r-i);
		}
		// cout << "|" << umap[i] << endl;
	}
	auto res = min_element(begin(umap),end(umap), [](auto& x, auto& y)
		{
			return x.second < y.second;
		});
	cout << "idx: " << res->first  << "|" << res->second << endl;



	return 0;
}
