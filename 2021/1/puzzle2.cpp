#include <bits/stdc++.h>
#include <exception>
#include "../md5.h"
#include "../util.h"

using namespace std;

int main() 
{
//  	auto lol = read_input();
//  	for (auto s : lol) cout << s << std::endl;
//  	return 0;
	int first, second, third;
	int temp;
	int current_sum, last_sum;
	cin >> first >> second >> third ;
	int counti = 0;
	while (!cin.eof())
	{
		cin >> temp;
		cout << temp << "\n";
		last_sum = first + second + third;
		current_sum = second + third + temp;

		if (last_sum < current_sum)
			counti++;

		first = second;
		second = third;
		third = temp;
	}
	cout << counti;
}
