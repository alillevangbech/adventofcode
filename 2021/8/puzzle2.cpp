#include <bits/stdc++.h>
#include "../util.h"
using namespace std;
#define n 14
#define signal 10
#define output 4
using ccmap = unordered_map<char, char>;
char toNumber(const string& s, const ccmap& fmt);

int main() 
{
	ll lsum = 0;
	char a[n][10];
	bool sep = true;
	int s,sum = 0;
	string set,out;
	vector<string> v(n);
	ccmap umap {{'a','\0'},{'b','\0'},{'c','\0'},{'d','\0'},{'e','\0'},{'f','\0'},{'g','\0'}};
	while (scanf("%s %s %s %s %s %s %s %s %s %s | %s %s %s %s", a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9], a[10], a[11], a[12], a[13]) != EOF) {
//		printf("%s %s %s %s %s %s %s %s %s %s | %s %s %s %s\n", a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9], a[10], a[11], a[12], a[13]);
		for (int i = 0; i < n; i++) {
			v[i] = std::string(a[i]);
			std::sort(v[i].begin(), v[i].end());
		}

		string x6,x5,x2,x3;
		string x8 = *std::find_if(v.begin(), v.begin()+signal, [](const auto& x) { return x.size() == 7;});
		string x1 = *std::find_if(v.begin(), v.begin()+signal, [](const auto& x) { return x.size() == 2;});
		string x7 = *std::find_if(v.begin(), v.begin()+signal, [](const auto& x) { return x.size() == 3;});
		string x4 = *std::find_if(v.begin(), v.begin()+signal, [](const auto& x) { return x.size() == 4;});


		// finding a
		set_symmetric_difference(begin(x1),end(x1),begin(x7),end(x7),back_inserter(set));
		umap['a'] = set.front();
		set.clear();
		
		for (auto i = 0; i < signal; i++) {
			if (v[i].size() != 6) continue;
			auto x = v[i];
			set_intersection(begin(x1),end(x1),begin(x),end(x),back_inserter(set));
			
			if (set.size() == 1) {
				// finding f
				x6 = x;
				umap['f'] = set.front();
				
				// finding c
				set_symmetric_difference(begin(set),end(set),begin(x1),end(x1),begin(set));
				umap['c'] = set.front();
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
				// finding e
				x5 = x;
				umap['e'] = set.front();
			}
			set.clear();
		}
		set.clear();

		for (auto i = 0; i < signal; i++) {
			if (v[i].size() != 5 || v[i] == x5) continue;
			auto x = v[i];
			
			if (x.find(umap['e']) == string::npos) {
				/* 3 */
				// finding b
				x3 = x;
				set = x3;
				set.push_back(umap['e']);
				sort(begin(set),end(set));
				set_symmetric_difference(begin(set),end(set),begin(x8),end(x8),begin(set));
				umap['b'] = set.front();
			} 
		}

		// finding d
		for (char c : x4)
			if (c != umap['b'] && c != umap['c'] && c != umap['f']) {
				umap['d'] = c;
			}
		
		// finding g
		for (char c : x8)
			if (c != umap['a'] && c != umap['b'] && c != umap['c'] &&
				c != umap['d'] && c != umap['e'] && c != umap['f']) {
				umap['g'] = c;
			}


		for (int i = signal; i < n; i++) {
			out.push_back(toNumber(v[i], umap));
		}
		lsum += std::stoi(out);

		out.clear();
		set.clear();
		umap.clear();
	}
	cout << lsum << endl;
	return 0;
}



char toNumber(const string& s, const ccmap& fmt)
{
	string res;
	for (auto x : s)
		res.push_back(find_if(begin(fmt),end(fmt),[=](const auto& y){ return y.second == x;})->first);

	sort(begin(res),end(res));
	if (res == "abcefg")
		return '0';
	else if (res == "cf")
		return '1';
	else if (res == "acdeg")
		return '2';
	else if (res == "acdfg")
		return '3';
	else if (res == "bcdf")
		return '4';
	else if (res == "abdfg")
		return '5';
	else if (res == "abdefg")
		return '6';
	else if (res == "acf")
		return '7';
	else if (res == "abcdefg")
		return '8';
	else if (res == "abcdfg")
		return '9';
	else
		cout << "FUCK --> " << res << endl;
	return '-';
}
