#include <bits/stdc++.h>
#include "../util.h"
using namespace std;
#define MAX_DAYS 256
int main() 
{
	int r;
	unordered_map<char, ll> v,tmp;
	while (cin >> r) {
		v[r]++;
	}
	int days = 0;
	while (days < MAX_DAYS) {
		for (int i = 8; i >= 0; i--) {
			if (i == 0) {
				tmp[8] = v[0];
				tmp[6] += v[0];
			} else {
				tmp[i-1] = v[i];
			}
		}
		v.clear();
		v = tmp;
		tmp.clear();
		days++;
	}
	ll sum;
	for (int i = 8; i >= 0; i--) {
		sum += v[i];
	}
	cout << sum << endl;
	return 0;
}
