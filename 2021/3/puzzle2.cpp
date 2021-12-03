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
	double threshold = input.size() / 2.0;
	int length = input.size();
	vector<int> v(n, 0);
	vector<bits> b;
	transform(begin(input), end(input), back_inserter(b),[](const string& s)
		{
			return bits(s);
		});
	
	auto thresh = [](int i, double threshold) { return i >= threshold;};
	vector<bits> tmp1, tmp2;

	bool val = 0;
	tmp1 = b;
	int cur_bit = n - 1;
	while (tmp1.size() != 1) {
		threshold = tmp1.size() / 2.0;
		cout << threshold << "-" << tmp1.size() << endl;
		for (auto i = 0; i < tmp1.size(); i++) {
			v[cur_bit] += tmp1[i][cur_bit];
		}
		val = thresh(v[cur_bit],threshold);
		cout << v[cur_bit] << ";" << val << endl;
		for (auto i = 0; i < tmp1.size(); i++) {
			if (tmp1[i][cur_bit] == val)
				tmp2.push_back(tmp1[i]); 
		}
		tmp1 = tmp2;
		tmp2.clear();
		cur_bit--;
	}
	int first = tmp1[0].to_ulong(); 
	
	cout << endl;
	val = 0;
	tmp1 = b;
	cur_bit = n - 1;
	tmp1 = b;
	tmp2.clear();
	fill(begin(v),end(v),0);
	while (tmp1.size() != 1) {
		threshold = tmp1.size() / 2.0;
		cout << threshold << "-" << tmp1.size() << endl;
		for (auto i = 0; i < tmp1.size(); i++) {
			v[cur_bit] += tmp1[i][cur_bit];
		}
		val = !thresh(v[cur_bit],threshold);
		cout << v[cur_bit] << ";" << val << endl;
		for (auto i = 0; i < tmp1.size(); i++) {
			if (tmp1[i][cur_bit] == val)
				tmp2.push_back(tmp1[i]); 
		}
		tmp1 = tmp2;
		tmp2.clear();
		cur_bit--;
	}
	cout << tmp1[0] << endl;
	int second = tmp1[0].to_ulong(); 
	cout << second * first << endl;

	return 0;
}
