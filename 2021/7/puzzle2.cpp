#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include "../util.h"
using namespace std;
int main() 
{
	int x;
	int step;
	int factor;
	int sum;
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
		umap[i] = 0;
		for (int r : v) {

			sum = 0;
			factor = 1;
			step = r < i ? 1 : -1;
			while (r != i) {
				r += step;
				sum += factor;
				factor++;
			}
			
			umap[i] += sum;
		}
	}
	auto res = min_element(begin(umap),end(umap), [](auto& x, auto& y)
		{
			return x.second < y.second;
		});
	cout << "idx: " << res->first  << "|" << res->second << endl;



	return 0;
}
