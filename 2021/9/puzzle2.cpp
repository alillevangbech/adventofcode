#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>
#include "../util.h"
using namespace std;
int inline dx(int y, int x, int n_row) { return y*n_row + x;}
int inline dxmax(int n_col, int n_row) { return n_col*n_row + 1;}

void inline add_edge(std::vector<int> adj[], int src, int dest)
{
    adj[src].push_back(dest);
}

int BFS(std::vector<int> adj[], const vector<int>& data, int src, int n)
{
	std::queue<int> q;
	bool visited[n];
	int f,s;
	for (int i = 0; i < n; i++) {
		visited[i] = false;
	}
	
	int count = 1;
	visited[src] = true;
	q.push(src);

	while (!q.empty()) {
		f = q.front();
		q.pop();
		for (int i = 0; i < adj[f].size(); i++) {
			s = adj[f][i];
			if (visited[s] == false) {
				visited[s] = true;
				if (data[s] != 9) {
					count++;
					q.push(s);
				}
			}
		}
	}
	return count;
}

int main() 
{
	auto input = read_input();
	// print_output(input);
	int n_row = input[0].size();
	int n_col = input.size();
	vector<int> v;
	int n = dxmax(n_row, n_col);
	vector<int> adj[n];
	for (int i = 0; i < n_col; i++) {
		for (int j = 0; j < n_row; j++) {
			v.push_back(input[i][j] - '0');
		}
	}

	int count = 0;
	bool up,down,left,right;
	vector<int> lows;
	for (int y = 0; y < n_col; y++) {
		for (int x = 0; x < n_row; x++) {
			int idx = dx(y,x,n_row);
			int e = v[idx];

			left = x - 1 >= 0;
			up = y - 1 >= 0;
			right = x + 1 < n_row;
			down = y + 1 < n_col;
			count = 0;

			if (left) {
				add_edge(adj, idx, dx(y,x - 1,n_row));
				if (e < v[dx(y,x - 1,n_row)])
					count++;
			} else {
				count++;
			}

			if (right) {
				add_edge(adj, idx, dx(y,x + 1,n_row));
				if (e < v[dx(y,x + 1,n_row)])
					count++;
			} else {
				count++;
			}

			if (down) {
				add_edge(adj, idx, dx(y+1,x,n_row));
				if (e < v[dx(y + 1,x,n_row)])
					count++;
			} else {
				count++;
			}

			if (up) {
				add_edge(adj, idx, dx(y-1,x,n_row));
				if (e < v[dx(y - 1,x,n_row)])
					count++;
			} else {
				count++;
			}

			if (count == 4) {
				lows.push_back(idx);
			}
		}
	}

	vector<int> sums;
	for (auto idx : lows) {
		int qq = BFS(adj,v,idx,n);
		sums.push_back(qq);
	}

	sort(begin(sums),end(sums));
	cout << accumulate(sums.end()-3, sums.end(), 1, multiplies<int>{}) << endl;

	return 0;
}
