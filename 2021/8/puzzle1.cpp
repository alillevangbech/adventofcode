#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include "../util.h"
using namespace std;
#define n 14
#define len 10

int main() 
{
	char a[n][len];
	int s,sum = 0;
	vector<string> v(n);
	while (scanf("%s %s %s %s %s %s %s %s %s %s | %s %s %s %s\n", a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9], a[10], a[11], a[12], a[13]) != EOF) {
		//printf("%s %s %s %s %s %s %s %s %s %s | %s %s %s %s\n", a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9], a[10], a[11], a[12], a[13]);
		for (int i = 0; i < n; i++)
			v[i] = std::string(a[i]);
		
		for (int i = 10; i < n; i++) {
			s = v[i].size();
			if (s == 2 || s == 4 || s == 3 || s == 7)
				sum++;
		}
	}
	cout << sum << endl;
	return 0;
}
