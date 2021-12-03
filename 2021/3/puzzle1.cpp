#include <algorithm>
#include <bits/stdc++.h>
#include <cstdlib>
#include <iterator>
#include "../util.h"
using namespace std;
#define n 12
#define bits bitset<n>
int main() 
{
	auto input = read_input();

	vector<int> v(n, 0);
	vector<bits> b;
	transform(begin(input), end(input), back_inserter(b),[](const string& s)
		{
			return bits(s);
		});
	
	for (auto x : b) {
		for (int i = 0; i < n; i++)
		{
			v[i] += x[i];
		}
	}


	vector<bool> bi1;
	bits bi2;
	int threshold = input.size() / 2;
	transform(begin(v),end(v),back_inserter(bi1),
		[&](int i) 
		{
			return i > threshold;
		});

	for (int i = 0; i < n; i++) {
		bi2[i] = bi1[i];
	}
	cout << bi2.to_ulong() * bi2.flip().to_ulong() << endl;

	return 0;
}
