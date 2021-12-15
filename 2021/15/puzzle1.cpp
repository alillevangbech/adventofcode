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
