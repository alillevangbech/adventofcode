#include <bits/stdc++.h>
#include <iterator>
#include <queue>
#include "../util.h"
using namespace std;
#define INF 100000
typedef pair<int,int> IIP;
typedef vector<vector<IIP>> _graph;
void djik(int s, _graph& graph, vector<int>& d);
int inline idx(int y, int x, int nx) {return y*nx+x;};
void spawnright(vector<vector<int>>& matrix);
void spawndown(vector<vector<int>>& matrix);
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
	spawnright(matrix);
	spawndown(matrix);

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

void djik(int s, _graph& graph, vector<int>& d) {
	int n = graph.size();
	d.assign(n,INF);
	vector<bool> visited(n,false);
	d[s] = 0;
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
	int u,alt;
	
	for (int i = 0; i < graph.size(); i++)
		q.push({d[i],i});

	while (!q.empty()) {
		u = q.top().second;
		q.pop();
		
		if (visited[u] == true)
			continue;

		visited[u] = true;

		for (auto v : graph[u]) {
			alt = d[u] + v.second;
			if (alt < d[v.first]) {
				d[v.first] = alt;
				q.push({alt, v.first});
			}
		}
	}
}

void spawnright(vector<vector<int>>& matrix) {
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

void spawndown(vector<vector<int>>& matrix) {
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

