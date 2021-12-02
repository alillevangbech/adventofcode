#include <bits/stdc++.h>
#include "../util.h"

using namespace std;



int main() 
{
	long long hor_depth = 0;
	long long depth = 0;
	std::string s1;
	int i1;
	while (cin >> s1 >> i1)
	{
		if (s1 == "forward") {
			hor_depth += i1;
		} else if ( s1 == "up") {
			depth = fmax(depth - i1, 0);
		} else if ( s1 == "down") {
			depth += i1;
		}
	}
	cout << depth * hor_depth << endl;


}
