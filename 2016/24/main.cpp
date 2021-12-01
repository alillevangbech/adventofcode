#include "../includes.h"
#include <algorithm>
#include <queue>
static int max_x = 0;
static int max_y = 0;
static int min_x = 0;
static int min_y = 0;
#define N 8 // max cities;

void add_edge(std::vector<int> adj[], int src, int dest)
{
    adj[src].push_back(dest);
}

void BFS(std::vector<int> adj[], int src, int n, int dist[])
{
	std::queue<int> q;
	bool visited[n];
	int f,s;
	for (int i = 0; i < n; i++) {
		visited[i] = false;
		dist[i] = INT_MAX;
	}
	
	visited[src] = true;
	dist[src] = 0;
	q.push(src);

	while (!q.empty()) {
		f = q.front();
		q.pop();
		
		for (int i = 0; i < adj[f].size(); i++) {
			s = adj[f][i];
			if (visited[s] == false) {
				visited[s] = true;
				dist[s] = dist[f] + 1;
				q.push(s);
			}
		}
	}	
}

int TSP(int graph[N][N], int s)
{
	std::vector<int> vertex;
	for (int i = 0; i < N; i++)
		if (i != s)
			vertex.push_back(i);

	int min_path = INT_MAX;
	do {
		
		int current_pathweight = 0;

		int k = s;
		for (int i = 0; i < vertex.size(); i++) {
			current_pathweight += graph[k][vertex[i]];
			k = vertex[i];
		}
		current_pathweight += graph[k][s];

		min_path = std::min(min_path, current_pathweight);

	} while (std::next_permutation(vertex.begin(),vertex.end()));

	return min_path;
}


int main() 
{
	auto lines = read_input();
	max_y = lines.size();
	max_x = lines[0].size();
	int max_idx = d2maxidx(max_x, max_y);
	int cur_idx = 0;
	std::vector<int> adj[max_idx];
	int dist[max_idx];
	std::vector<std::pair<int,int>> goals;

	for (int y = min_y; y < max_y; y++) {
		for (int x = min_x; x < max_x; x++) {
			char c = lines[y][x];
			cur_idx = d2idx(x, y, max_x);
			if (c == '#') continue;

			if (c - '0' >= 0 && c - '0' <= 9)
				goals.push_back({cur_idx, c - '0'});

			if (x - 1 >= min_x && lines[y][x-1] != '#') {
				add_edge(adj, cur_idx, d2idx(x-1, y, max_x));
			}

			if (x + 1 < max_x && lines[y][x+1] != '#') {
				add_edge(adj, cur_idx, d2idx(x+1, y, max_x));
			}

			if (y - 1 >= min_y && lines[y-1][x] != '#') {
				add_edge(adj, cur_idx, d2idx(x, y-1, max_x));
			}

			if (y + 1 < max_y && lines[y+1][x] != '#') {
				add_edge(adj, cur_idx, d2idx(x, y+1, max_x));
			}
		}
	}
	/* 0 : 1 : 2 : 3 : 4 : 5 : 6 : 7 : 8 : 9 : Cities
	 * 
	 *	
	 *
	 *
	 */
	// Citi is based on index.
	
	std::sort(goals.begin(),goals.end(),
			[](const std::pair<int,int>& p1, const std::pair<int,int>& p2)
			{return p1.second < p2.second;});

	int cities[N][N];
	for (int i = 0; i < N; i++) {
		auto p = goals[i];
		BFS(adj, p.first, max_idx, dist);
		for (int j = 0; j < N; j++) {
			cities[i][j] = dist[goals[j].first];
		}
	}

	int s = 0;
	std::cout << TSP(cities, s) << std::endl;
}
