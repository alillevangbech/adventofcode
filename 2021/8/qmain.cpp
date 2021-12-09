#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
#include <unordered_map>
#include "../util.h"
using namespace std;
#define n 14
#define signal 10
#define output 4
using ccmap = unordered_map<char, char>;
void transform(string s, string format) {
	string fn = "daefbgc";
	for (auto& c : fn) {
	}
}
int toNumber(string s);
void getMapping();

int main() 
{
	char a[n][10];
	bool sep = true;
	int s,sum = 0;
	string set;
	vector<string> v(n);
	ccmap umap {{'a','\0'},{'b','\0'},{'c','\0'},{'d','\0'},{'e','\0'},{'f','\0'},{'g','\0'}};
	while (scanf("%s %s %s %s %s %s %s %s %s %s | %s %s %s %s", a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9], a[10], a[11], a[12], a[13]) != EOF) {
		printf("%s %s %s %s %s %s %s %s %s %s | %s %s %s %s\n", a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9], a[10], a[11], a[12], a[13]);
		for (int i = 0; i < n; i++) {
			v[i] = std::string(a[i]);
			std::sort(v[i].begin(), v[i].end());
		}
		set.clear();

		string x6,x5,x2,x3;
		string x8 = *std::find_if(v.begin(), v.begin()+signal, [](const auto& x) { return x.size() == 8;});
		string x1 = *std::find_if(v.begin(), v.begin()+signal, [](const auto& x) { return x.size() == 2;});
		string x7 = *std::find_if(v.begin(), v.begin()+signal, [](const auto& x) { return x.size() == 3;});
		string x4 = *std::find_if(v.begin(), v.begin()+signal, [](const auto& x) { return x.size() == 4;});
		set_symmetric_difference(begin(x1),end(x1),begin(x7),end(x7),back_inserter(set));
		umap[set.front()] = 'a';
		cout << set.front() << "|" << 'a' << endl;
		set.clear();
		
		for (auto i = 0; i < signal; i++) {
			if (v[i].size() != 6) continue;
			auto x = v[i];
			set_intersection(begin(x1),end(x1),begin(x),end(x),back_inserter(set));
			
			if (set.size() == 1) {
				x6 = x;
				// can now find both c & f
				umap[set.front()] = 'f'; 
				cout << set.front() << "|" << 'f' << endl;
				set_symmetric_difference(begin(set),end(set),begin(x1),end(x1),begin(set));
				umap[set.front()] = 'c';
				cout << set.front() << "|" << 'c' << endl;
				break;
			}
			set.clear();
		}
		set.clear();

		for (auto i = 0; i < signal; i++) {
			if (v[i].size() != 5) continue;
			auto x = v[i];
			// cout << x << "--" << x6 << endl;
			set_symmetric_difference(begin(x),end(x),begin(x6),end(x6),back_inserter(set));
			
			if (set.size() == 1) {
				x5 = x;
				umap[set.front()] = 'e';
				cout << set.front() << "|" << 'e' << endl;
				break;
			}
			set.clear();
		}
		set.clear();

		for (auto i = 0; i < signal; i++) {
			if (v[i].size() != 5 || v[i] == x5) continue;
			auto x = v[i];
			auto q = find_if(begin(umap), end(umap), [](const auto& t) { return t.second == 'e';});
			
			if (x.find(q->first) == string::npos) {
				/* 3 */
				x3 = x;
				set = x3;
				set.push_back(q->first);
				sort(begin(set),end(set));
				set_symmetric_difference(begin(set),end(set),begin(x8),end(x8),begin(set));
				umap[set.front()] = 'b' ;
				cout << set.front() << "|" << 'b' << endl;
			} 
		}

		// finding d
		for (char c : x4)
			if (umap[c] != 'b' && umap[c] != 'c' && umap[c] != 'f') {
				umap[c] = 'd';
				cout << c << "|" << 'd' << endl;
			}
		
		// finding g
		for (char c : x8)
			if (umap[c] != 'a' && umap[c] != 'b' && umap[c] != 'c' &&
				umap[c] != 'd' && umap[c] != 'e' && umap[c] != 'f') {
				umap[c] = 'g';
				cout << c << "|" << 'g' << endl;
			}

		set.clear();

		
		/* a b f e b*/


		
		
//		sort(begin(x1),end(x1));
//		sort(begin(x7),end(x7));
//		set_intersection(begin(x1), end(x1), begin(x7), end(x7), back_inserter(set));
		set.clear();
	}
	return 0;
}



int toNumber(const string& s, const ccmap& fmt)
{
	string x;
	for (auto x : s)
		; // x.pushback(fmt[
	if (s == "abcefg")
		return 0;
	else if (s == "cf")
		return 1;
	else if (s == "acdeg")
		return 2;
	else if (s == "acdfg")
		return 3;
	else if (s == "bcdf")
		return 4;
	else if (s == "abdfg")
		return 5;
	else if (s == "abdefg")
		return 6;
	else if (s == "acf")
		return 7;
	else if (s == "abcdefg")
		return 8;
	else if (s == "abcdfg")
		return 9;
	else
		cout << "FUCK --> " << s << endl;
	return -1;
}

/*
 *
		for (auto x : x7)
			if (x1.end() == std::find(begin(x1),end(x1),x)) {
				umap['a'] = x;
				break;
			}

		for (int i = 0; i < signal; i++) {
			if (v.size() != 6) continue;
			auto w = v[i];
			bool allfound = true; // assume true
			
			for (auto x : x1) {
				if (w.end() == std::find(begin(w),end(w),x))
					allfound = false;
		}
	*/
