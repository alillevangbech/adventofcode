#include <bits/stdc++.h>
#include "../util.h"
#define bits bitset<32>
using namespace std;
int main() 
{
	auto input = read_input();
	int cb,oz,n = input[0].size();
	vector<int> ones(n, 0), zeros(n, 0);
	vector<bool> tmp;
	vector<bits> b;
	transform(begin(input), end(input), back_inserter(b),[](const string& s){ return bits(s); });
	for (auto x : b) 
		for (int i = 0; i < n; i++)
			if (x[i])
				ones[i]++;
			else
				zeros[i]++;
	transform(begin(ones), end(ones), begin(zeros), back_inserter(tmp), greater_equal<int>{});
	cb = binary(tmp);
	tmp.flip();
	oz = binary(tmp);
	cout << cb * oz << endl;
	return 0;
}
