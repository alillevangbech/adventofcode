#include <bits/stdc++.h>
#include <iterator>
#include "../util.h"
using namespace std;
#define INF INT32_MAX
typedef pair<int,int> IIP;
typedef vector<vector<IIP>> _graph;
void djik(int s, _graph& graph, vector<int>& d);
vector<int> restore_path(int s, int t, vector<int> const& p);
int inline idx(int y, int x, int nx) {return y*nx+x;};
void pm(const vector<vector<int>>& matrix);
void pmm(const vector<vector<pair<int,int>>>& matrix);
void fuckerright(vector<vector<int>>& matrix);
void fuckerdown(vector<vector<int>>& matrix);
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
	fuckerright(matrix);
	fuckerdown(matrix);

	nx = matrix[0].size();
	ny = matrix.size();
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

	vector<int> d;
	djik(idx(0, 0, nx), graph, d);
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

void fuckerright(vector<vector<int>>& matrix) {
	int n = 5;
	vector<vector<int>> v[5];
	vector<vector<int>> tmp;
	v[0] = matrix;
	for (int i = 1; i < n; i++) {
		v[i] = v[i-1];
		for (int y = 0; y < v[i].size(); y++) {
			for (int x = 0; x < v[i][y].size(); x++) {
				v[i][y][x] = v[i][y][x] + 1 == 10 ? 1 : v[i][y][x] + 1;
			}
			move(begin(v[i][y]), end(v[i][y]), back_inserter(matrix[y]));
		}
	}
}

void fuckerdown(vector<vector<int>>& matrix) {
	int n = 5;
	vector<vector<int>> tmp;
	tmp = matrix;
	for (int i = 1; i < n; i++) {
		for (auto& yy : tmp) {
			for (auto& xx : yy) {
				xx = xx + 1 == 10 ? 1 : xx + 1;
			}
		}
		copy(begin(tmp), end(tmp), back_inserter(matrix));
	}

}

