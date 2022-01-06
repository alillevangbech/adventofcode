#include <bits/stdc++.h>
#include "../md5.h"
 
using namespace std;

int main() 
{
	int current, last;
	int countd = 0, counti = 0;
	last = INT_MAX;
	while (!cin.eof())
	{
		cin >> current;
		if (countd == 0 && counti == 0)
			last = current;

		if (last < current)
			counti++;
		else 
			countd++;

		last = current;
	}
	cout << counti;
}
