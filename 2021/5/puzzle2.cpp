#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include "../util.h"
using namespace std;
#define n 1000
struct vent {
	int x1,x2,y1,y2;
	vent(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {};
	void print () {
	cout << x1 << ";" << y1 << ";" << x2 << ";" << y2 << endl;
	};
};

double slope(vent& v) {
	double delta_x = (double)v.x2 - (double)v.x1;
	double delta_y = (double)v.y1 - (double)v.y2;
	double radian = atan2(delta_y,delta_x);
	double degree = round(57.2957795 * radian);
	degree += degree < 0 ? 360 : 0;
	return degree;
}

int main() {
	int ret;
	int x1,x2,y1,y2;
	vector<vent> s;
	vector<vector<int>> map{n,vector<int>(n,0)};
	while ((ret = scanf("%d %d %d %d\n", &x1, &y1, &x2, &y2)) != EOF) {
		assert(ret == 4);
		s.push_back(vent{x1,y1,x2,y2});
	}

	for (auto& v : s) {
		int degree = slope(v);

		switch (degree) {
			case 0:
				for (int i = v.x1; i <= v.x2; i++) map[v.y1][i]++; 
				break;
			case 45:
				for (int x = v.x1, y = v.y1; x <= v.x2 && y >= v.y2; x++,y--) map[y][x]++; 
				break;
			case 90:
				for (int i = v.y1; i >= v.y2; i--) map[i][v.x1]++; 
				break;
			case 135:
				for (int x = v.x1, y = v.y1; x >= v.x2 && y >= v.y2; x--,y--) map[y][x]++; 
				break;
			case 180:
				for (int i = v.x1; i >= v.x2; i--) map[v.y1][i]++; 
				break;
			case 225:
				for (int x = v.x1, y = v.y1; x >= v.x2 && y <= v.y2; x--,y++) map[y][x]++; 
				break;
			case 270:
				for (int i = v.y1; i <= v.y2; i++) map[i][v.x1]++; 
				break;
			case 315:
				for (int x = v.x1, y = v.y1; x <= v.x2 && y <= v.y2; x++,y++) map[y][x]++; 
				break;
			default:
				break;
		};
	}

	int count = 0;
	for_each(begin(map), end(map), [&](auto& v)
	{
		count += std::count_if(begin(v),end(v),[&](auto& vv)
		{
			return vv > 1;
		});
	});
	cout << count << endl;

}
