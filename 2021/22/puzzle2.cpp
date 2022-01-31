#include <bits/stdc++.h>
#include "../util.h"
using namespace std;
#define MAX 50
struct cube {
	public:
	ll on,xmin,xmax,ymin,ymax,zmin,zmax;
	ll volume() const { return on * (xmax-xmin+1) * (ymax-ymin+1) * (zmax-zmin+1); }
	void print() const {printf("%lld %lld %lld %lld %lld %lld %lld\n",on,xmin,xmax,ymin,ymax,zmin,zmax);}
};

optional<cube> intersect(cube const &A, cube const &B);

int main() {

	auto input = read_input();
	vector<cube> list, core, toadd;
	cube *c, *c_on, *c_off;
	for (auto s : input) {
		list.push_back({});
		c = &list.back();
		sscanf(s.c_str(),"%lld %lld %lld %lld %lld %lld %lld",&c->on,&c->xmin,&c->xmax,&c->ymin,&c->ymax,&c->zmin,&c->zmax);
		//c->print();
	}
	
	for (cube l : list) {
//		if (abs(l.xmin) > MAX) continue; part 1 
		toadd.clear();
		if (l.on) {
			toadd.push_back(l);
		}
		for (auto c : core) {
			auto tmp = intersect(c,l);
			if (tmp.has_value())
				toadd.push_back(tmp.value());
		}
		core.insert(core.end(),toadd.begin(),toadd.end());
	}
	
	ll sum = 0;
	for (auto c : core) {
		sum += c.volume();
	}
	cout << sum << endl;
}

optional<cube> intersect(cube const &A, cube const &B)
{
	cube c {-A.on,
	       max(A.xmin, B.xmin),
	       min(A.xmax, B.xmax),
	       max(A.ymin, B.ymin),
	       min(A.ymax, B.ymax),
	       max(A.zmin, B.zmin),
	       min(A.zmax, B.zmax)};

	if (c.xmin > c.xmax || c.ymin > c.ymax || c.zmin > c.zmax)
		return {};
	else
		return c;
}
