#include <bits/stdc++.h>
#include <exception>
#include "../md5.h"
#include "../util.h"
 
using namespace std;

int main() 
{
	int first, second, third;
	int temp;
	int current_sum, last_sum;
	cin >> first >> second >> third ;
	int counti = 0;
	while (!_EOF())
	{
		cin >> temp;
		last_sum = first + second + third;
		current_sum = second + third + temp;

		if (last_sum < current_sum)
			counti++;

		first = second;
		second = third;
		third = temp;
	}
	cout << counti << "\n";
}
