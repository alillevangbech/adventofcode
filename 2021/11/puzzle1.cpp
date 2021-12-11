#include <bits/stdc++.h>
#include <stack>
#include <utility>
#include "../util.h"
using namespace std;
typedef vector<int> vv;
void p(const vv& v, int xn);
int inline idx(int y, int x, int xn) {return y*xn+x;};
void add_edge(vector<int> graph[], int src, int dest) { graph[src].push_back(dest); };
int main() 
{
	string s;
	vv v;
	int cv = 0;
	int xn, yn, en;
	while (getline(cin,s)) {
		xn = s.size();
		for (auto x : s) v.push_back(x - '0');
		cv++;
	}
	yn = cv;
	en = xn*yn;
	vector<int> graph[en];

	int cur_idx;
	bool up,down,right,left;
	for (int y = 0; y < yn; y++) {
		for (int x = 0; x < xn; x++) {
			cur_idx = idx(y, x, xn);
			up = y - 1 >= 0;
			down = y + 1 < yn;
			left = x - 1 >= 0;
			right = x + 1 < xn;


			if (left && up)
				add_edge(graph, cur_idx, idx(y - 1, x - 1, xn));
			if (up)
				add_edge(graph, cur_idx, idx(y - 1, x, xn));
			if (up && right)
				add_edge(graph, cur_idx, idx(y - 1, x + 1, xn));
			if (right)
				add_edge(graph, cur_idx, idx(y, x + 1, xn));
			if (down && right)
				add_edge(graph, cur_idx, idx(y + 1, x + 1, xn));
			if (down)
				add_edge(graph, cur_idx, idx(y + 1, x, xn));
			if (down && left)
				add_edge(graph, cur_idx, idx(y + 1, x - 1, xn));
			if (left)
				add_edge(graph, cur_idx, idx(y, x - 1, xn));

			

		}
	}
	
/*
	p(v, xn);
	for (int i = 0; i < en; i++) {
		cout << "i: " << i << " ";
		for (auto x : graph[i])  {
			 cout << v[x];
		}
		cout << endl;
	}
*/

	int nsteps = 100;
	int step = 0;
	int flashes = 0;
	stack<int> nines;
	bool flashed[en];
	while (step < nsteps) {
		// step 1;
		for (auto& x : v) {
			x++;
		}

		// step 2;
		for (int y = 0; y < yn; y++) {
			for (int x = 0; x < xn; x++) {
				cur_idx = idx(y, x, xn);
				if (v[cur_idx] > 9)
					nines.push(cur_idx);
			}
		} 
		
		for (int i = 0; i < en; i++)
			flashed[i] = false;
		while (!nines.empty()) {
			int q = nines.top();
			nines.pop();
			if (flashed[q]) continue;
			flashed[q] = true;

			for (auto x : graph[q]) {
				if (flashed[x]) continue;
				v[x]++;
				if (v[x] > 9)
					nines.push(x);
			}
		}

		
		// step 3;
		for (auto& x : v) {
			if (x > 9) {
				flashes++;
				x = 0;
			}
		}

		step++;
	}

	cout << flashes << endl;
	return 0;
}

void p(const vv& v, int xn) {
	int x = 0;
	for (auto xx : v) {
		x++;
		cout << xx;
		if (x == xn) {
			x = 0;
			cout << endl;
		}
	}
	cout << endl;
}
