#include <bits/stdc++.h>
#include <numeric>
#include "../util.h"
using namespace std;
int inline dx(int y, int x, int n_row) {
return y*n_row + x;
}
int main() 
{
	auto input = read_input();
	// print_output(input);
	vector<int> v;
	int n_row = input[0].size();
	int n_col = input.size();
	for (int i = 0; i < n_col; i++) {
		for (int j = 0; j < n_row; j++) {
			v.push_back(input[i][j] - '0');
		}
	}

	bool up,down,left,right;
	vector<int> sum;
	for (int y = 0; y < n_col; y++) {
		for (int x = 0; x < n_row; x++) {
			int e = v[dx(y,x,n_row)];

			left = x - 1 >= 0;
			up = y - 1 >= 0;
			right = x + 1 < n_row;
			down = y + 1 < n_col;

			if (left) {
				if (e < v[dx(y,x - 1,n_row)])
					;//cout << e << " passed left" << endl;
				else
					continue;
			}

			if (right) {
				if (e < v[dx(y,x + 1,n_row)])
					; // cout << e << " passed right" << endl;
				else
					continue;
			}

			if (down) {
				if (e < v[dx(y + 1,x,n_row)])
					;// cout << e << " passed down" << endl;
				else
					continue;
			}

			if (up) {
				if (e < v[dx(y - 1,x,n_row)])
					;//cout << e << " passed right" << endl;
				else
					continue;
			}
			// cout << e << endl;
			sum.push_back(e);
		}
	}
	
	// cout << sum.size() << endl;
	cout << accumulate(begin(sum), end(sum), 0, [](auto i, auto j)
			{ return i + j + 1;}) << endl;

	return 0;
}
