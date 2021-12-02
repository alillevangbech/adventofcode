#include <bits/stdc++.h>
#include "../util.h"

using namespace std;



int main() 
{
	long long hor_depth = 0;
	long long depth = 0;
	long long aim = 0;
	std::string s1;
	int i1;
	while (cin >> s1 >> i1)
	{
		if (s1 == "forward") {
			hor_depth += i1;
			depth += aim*i1;
		} else if ( s1 == "up") {
			aim = fmax(aim - i1, 0);
		} else if ( s1 == "down") {
			aim += i1;
		}
	}
	cout << depth * hor_depth << endl;


}
