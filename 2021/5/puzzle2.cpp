#include <bits/stdc++.h>
#include "../util.h"
using namespace std;
#define n 1000
static int umap[n][n];
int main() 
{
	int stepx, stepy;
	int x,y,w,v;
	int i,j;
	int sum = 0;
	while (scanf("%d,%d -> %d,%d\n", &x, &y, &w, &v) != EOF) {
		stepx = x < w ? 1 : -1;
		stepy = y < v ? 1 : -1;
		for (i = y, j = x; i != v || j != w; i += (i != v ? stepy : 0), j += (j != w) ? stepx : 0)
			umap[i][j]++;
		umap[i][j]++;
	}
	std::for_each(umap, umap + n, [&](const auto& m)
	{
		std::for_each(m, m + n, [&](const auto& _m)
		{
			sum += _m > 1;
		});
	});
	cout << sum << endl;
	return 0;
}
