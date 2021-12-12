#include <bits/stdc++.h>
#include <unordered_map>
#include "../util.h"
using namespace std;
typedef std::unordered_map<string, int> simap;
typedef std::unordered_map<int, string> ismap;
void add_edge(vector<int> graph[], int src, int dest) { graph[src].push_back(dest); };
bool isupper(std::string s) { for (auto c : s) if (!isupper(c)) return false; return true;}
void printpath(vector<int>& path, ismap& map)
{
	int size = path.size();
	for (int i = 0 ; i < size; i++) {
		cout << map[path[i]] << " ";
	}
	cout << endl;
}
bool isVisited(int x, vector<int>& path, ismap& map)
{
	int size = path.size();
	for (int i = 0 ; i < size; i++) {
		if (path[i] == x && !isupper(map[path[i]])) {
			return true;
		}
	}
	return false;
}

#define n 10
int main() 
{
	char s1[n],s2[n];
	string str1,str2;
	unordered_map<string, int> umap{};
	unordered_map<int, string> fmap{}; 
	int next = 0;
	auto input = read_input();
	for (auto s : input) {
		sscanf(s.c_str(), "%s %s", s1, s2);
		str1 = std::string(s1);
		str2 = std::string(s2);
		if (umap.find(str1) == umap.end()) {
			umap[str1] = next;
			fmap[next] = str1;
			next++;
		}
		if (umap.find(str2) == umap.end()) {
			umap[str2] = next;
			fmap[next] = str2;
			next++;
		}
	}

	int uniq = fmap.size();	
	vector<int> v[uniq]; // probably do something smarter here;
	for (auto& s: input) {
		sscanf(s.c_str(), "%s %s", s1, s2);
		str1 = std::string(s1);
		str2 = std::string(s2);
		add_edge(v, umap[str1], umap[str2]);
		add_edge(v, umap[str2], umap[str1]);
	}

	// BFS
	queue<vector<int>> q;
	vector<int> path;
	path.push_back(umap["start"]);
	q.push(path);
	int count = 0;
	int dst = umap["end"];
	while (!q.empty()) {
		path = q.front();
		q.pop();
		int last = path[path.size()-1];
		
		if (last == dst) {
			count++;
		}

		for (int i = 0; i < v[last].size(); i++) {
			if (!isVisited(v[last][i], path, fmap)) {
				vector<int> newpath(path);
				newpath.push_back(v[last][i]);
				q.push(newpath);
			}
		}
	}
	cout << count << endl;

	return 0;
}
