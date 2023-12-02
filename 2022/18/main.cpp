#include <algorithm>
#include <cstdio>
#include <stdio.h>
#include <tuple>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <numeric>
#include <ranges>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include "../util.h"
using namespace std;
namespace rv = std::ranges::views;
namespace sv = std::views;
using cube = tuple<int,int,int>;
#define ALL_CUBE_SIDES_EXPOSED 6


int main() {
	auto lines = read_input();
	vector<cube> cubes;
	for (auto s : lines) {
		int x,y,z;
		sscanf(s.c_str(),"%d,%d,%d", &x, &y, &z);
		cubes.push_back(tie(x,y,z));
	}

	ll sum = 0;
	auto sides = [&sum](cube out, cube in){
		auto [xin, yin, zin] = in;
		auto [xout, yout, zout] = out;

		sum -= xin == xout && yin == yout && (zout == zin -1 || zout == zin + 1);
		sum -= xin == xout && zin == zout && (yout == yin -1 || yout == yin + 1);
		sum -= zin == zout && yin == yout && (xout == xin -1 || xout == xin + 1);
	};

	auto minx = get<0>(*min_element(begin(cubes), end(cubes), [](cube x, cube y){return get<0>(x) < get<0>(y);}));
	auto miny = get<1>(*min_element(begin(cubes), end(cubes), [](cube x, cube y){return get<1>(x) < get<1>(y);}));
	auto minz = get<2>(*min_element(begin(cubes), end(cubes), [](cube x, cube y){return get<2>(x) < get<2>(y);}));
	auto maxx = get<0>(*max_element(begin(cubes), end(cubes), [](cube x, cube y){return get<0>(x) > get<0>(y);}));
	auto maxy = get<1>(*max_element(begin(cubes), end(cubes), [](cube x, cube y){return get<1>(x) > get<1>(y);}));
	auto maxz = get<2>(*max_element(begin(cubes), end(cubes), [](cube x, cube y){return get<2>(x) > get<2>(y);}));

	printf("max: %d,%d,%d\nmin: %d,%d,%d\n", get<0>(cubes.front()),maxy,maxz,minx,miny,minz);


}
