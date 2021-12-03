#include <bits/stdc++.h>
#include "../util.h"
#define bits bitset<32>
using namespace std;
unsigned fun(vector<bits> b, bool bit, int n)
{
	vector<int> o(n,0), z(n,0);
	int cur_bit = n - 1;
	auto common = [&]() {return bit ? o[cur_bit] >= z[cur_bit] : o[cur_bit] < z[cur_bit];};
	while (b.size() != 1) { 
		for_each(b.begin(), b.end(), [&](const bits& bz) { if (bz[cur_bit]) o[cur_bit]++; else z[cur_bit]++;});
		b.erase(remove_if(begin(b),end(b),[&](const bits& bz) {return bz[cur_bit] == !common();}),end(b));
		cur_bit--;
	}
	return b[0].to_ulong();
}

int main() 
{
	auto input = read_input();
	unsigned cb,oz,n = input[0].size();
	vector<bits> b;
	transform(begin(input), end(input), back_inserter(b),[](const string& s){ return bits(s); });
	oz = fun(b,1,n);
	cb = fun(b,0,n);
	cout << cb * oz << endl;
	return 0;
}
