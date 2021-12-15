#include <bits/stdc++.h>
#include <cstdint>
#include <cstdio>
#include "../util.h"
using namespace std;
#define INF INT32_MAX
typedef pair<int,int> IIP;
typedef vector<vector<IIP>> _graph;
void djik(int s, _graph& graph, vector<int>& d, vector<int>& p);
vector<int> restore_path(int s, int t, vector<int> const& p);
int inline idx(int y, int x, int nx) {return y*nx+x;};
void pm(const vector<vector<int>>& matrix);
void pmm(const vector<vector<pair<int,int>>>& matrix);
int main() 
{
	char c;
	vector<vector<int>> matrix, bigmatrix;
	int nx, ny;
	matrix.push_back({});
	while((c = getchar()) != EOF) {
		if (c == '\n') {
			matrix.push_back({});
			continue;
		}
		matrix.back().push_back(c - '0');
	}
	matrix.erase(matrix.end());
	nx = matrix[0].size();
	ny = matrix.size();
	bigmatrix = matrix;



	int curidx = 0;
	_graph graph(ny*nx);
	auto addedge = [&curidx,nx,&matrix,&graph](int x, int y) {graph[curidx].push_back({idx(y, x, nx),matrix[y][x]});};
	bool right,left,up,down;
	for (int y = 0; y < ny; y++) {
		for (int x = 0; x < nx; x++) {
			curidx = idx(y, x, nx);
			
			left = x - 1 >= 0;
			right = x + 1 < nx;
			up = y - 1 >= 0;
			down = y + 1 < ny;

			if (left)
				addedge(x-1, y);
			if (right)
				addedge(x+1, y);
			if (up)
				addedge(x, y-1);
			if (down)
				addedge(x, y+1);
		}
	}
	

	vector<int> p,d;
	djik(idx(0, 0, nx), graph, d, p);
	cout << d[idx(ny-1, nx-1, nx)] << endl;



	return 0;
}

void pm(const vector<vector<int>>& matrix)
{
	for (auto yy : matrix) {
		for (auto xx : yy) {
			cout << xx;
		}
		cout << endl;
	}
}

void pmm(const vector<vector<pair<int,int>>>& matrix)
{
	for (auto yy : matrix) {
		for (auto xx : yy) {
			cout << xx.second;
		}
		cout << endl;
	}
}

void djik(int s, _graph& graph, vector<int>& d) {
	int n = graph.size();
	d.assign(n,INF);
	vector<bool> u(n, false);

	d[s] = 0;
	for (int i = 0; i < n; i++) {
		int v = -1;
		for (int j = 0; j < n; j++) {
			if (!u[j] && (v == -1 || d[j] < d[v]))
				v = j;
		}

		if (d[v] == INF)
			break;

		u[v] = true;
		for (auto edge : graph[v]) {
			int to = edge.first;
			int len = edge.second;

			if (d[v] + len < d[to]) {
				d[to] = d[v] + len;
			}
		}
	}
}

void fucker(const vector<vector<int>>& matrix);

