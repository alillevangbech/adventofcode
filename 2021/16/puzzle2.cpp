#include <algorithm>
#include <bits/stdc++.h>
#include <cassert>
#include <functional>
#include <numeric>
#include "../util.h"
using namespace std;
#define BITSIZE 4
int parse(vector<bool>::iterator b, ull &sum);


int main() 
{
	char c;
	unsigned int i;
	bitset<BITSIZE> bits;
	string packet, tmp;
	vector<bool> package;
	while ((c = getchar()) != EOF) {
		if (c == '\n') continue;
		sscanf(&c, "%02x", &i);
		bits = i;
		for (int xx = BITSIZE - 1; xx >= 0; xx--)
			package.push_back(bits[xx]);
	}
//	for (auto x : package) 
//		cout << x;
//	cout << endl;
	ull sum = 0;
	parse(package.begin(), sum);
	cout << sum << endl;


	return 0;
}

int parse(vector<bool>::iterator b, ull &sum) {
	vector<ull> packs;
	auto begin = b, beginf = b;
	int version, id;
	beginf += 3;
	version = binary(begin,beginf);
	begin += 3;
	beginf += 3;
	id = binary(begin,beginf);
	begin = beginf;
//	cout << "version:" << version << endl;

	if (id == 4) {
		vector<bool> v;
		while (*beginf == 1) {
			beginf += 5;
			for (auto it = beginf-4; it != beginf; it++)
				v.push_back(*it);
		}
		beginf += 5;
		for (auto it = beginf-4; it != beginf; it++)
			v.push_back(*it);
		
//		cout << "literal decimal value:" << binary(v.begin(), v.end()) << endl;
		for (auto b : v) cout << b;
		cout << endl;
		sum = binary(v.begin(), v.end());
		cout << sum << endl;

		return beginf - b;
	} else {
		ull orig = sum, sneed;
		beginf += 1;
		int len, lentypeid = binary(begin,beginf);
		if (lentypeid == 0) {
			begin = beginf;
			beginf += 15;
			len = binary(begin,beginf);
			//beginf++;
			begin = beginf;
			while (beginf - begin < len) {
				sneed = orig;
				beginf += parse(beginf,sneed);
				packs.push_back(sneed);
			}
		} else {
			begin = beginf;
			beginf += 11;
			len = binary(begin,beginf);
			//beginf++;
			begin = beginf;
			for (int j = 0; j < len; j++) {
				sneed = orig;
				beginf += parse(beginf,sneed);
				packs.push_back(sneed);
			}
		}

		ull fuck;
		switch (id) {
		case 0:
			fuck = 0;
			for (ull x : packs)
				fuck += x;
			sum = fuck;
			break;
		case 1:
			fuck = 1;
			for (ull x : packs)
				fuck *= x;
			sum = fuck;
			if (packs.size() == 1) assert(sum == packs.front());
			break;
		case 2:
			sum = *std::min_element(packs.begin(),packs.end());
			break;
		case 3:
			sum = *std::max_element(packs.begin(),packs.end());
			break;
		case 5:
			assert(packs.size() == 2);
			sum = packs.front() > packs.back();
			break;
		case 6:
			assert(packs.size() == 2);
			sum = packs.front() < packs.back();
			break;
		case 7:
			sum = packs.front() == packs.back();
			break;
		default:
			break;
		}
		return beginf - b;
	}

	return 0;
}
