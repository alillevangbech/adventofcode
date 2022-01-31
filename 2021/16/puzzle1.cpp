#include <algorithm>
#include <bits/stdc++.h>
#include <stdint.h>
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
	//	cout << c << " : " << i << " : " << bits << endl;
	}
	ull sum = 0;
	parse(package.begin(), sum);
	cout << sum << endl;


	return 0;
}

int parse(vector<bool>::iterator b, ull &sum) {
	auto begin = b, beginf = b;
	int version, id;
	beginf += 3;
	version = binary(begin,beginf);
	begin += 3;
	beginf += 3;
	id = binary(begin,beginf);
	begin = beginf;
	sum += version;
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
		
		return beginf - b;
	} else {
		beginf += 1;
		int len, lentypeid = binary(begin,beginf);
		if (lentypeid == 0) {
			begin = beginf;
			beginf += 15;
			len = binary(begin,beginf);
			//beginf++;
			begin = beginf;
			while (beginf - begin < len)
				beginf += parse(beginf,sum);
		} else {
			begin = beginf;
			beginf += 11;
			len = binary(begin,beginf);
			//beginf++;
			begin = beginf;
			for (int j = 0; j < len; j++)
				beginf += parse(beginf,sum);
		}
	}

	return beginf - b;
}

