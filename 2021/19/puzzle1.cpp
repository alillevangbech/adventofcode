#include <bits/stdc++.h>
#include <cstdio>
#include <tuple>
#include "../util.h"
#define n 3
using namespace std;
void print2d(vector<vector<int>> m1) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << m1[i][j] << " "; 
		}
		cout << endl;
	}
}


struct P { 
	int x,y,z;
	P rotate(vector<vector<int>> const& matrix) const {
		P p;
		p.x = matrix[0][0]*x + matrix[0][1]*y + matrix[0][2]*z;
		p.y = matrix[1][0]*x + matrix[1][1]*y + matrix[1][2]*z;
		p.z = matrix[2][0]*x + matrix[2][1]*y + matrix[2][2]*z;
		return p;
	}
	bool operator<(P const &p) const
	{
		return make_tuple(x,y,z) < make_tuple(p.x,p.y,p.z);
	}
	bool operator==(P const &p) const
	{
		return make_tuple(x,y,z) == make_tuple(p.x,p.y,p.z);
	}
	P operator+(P const &p) const
	{
		return {x + p.x, y + p.y, z + p.z};
	}
	P operator-(P const &p) const
	{
		return {x - p.x, y - p.y, z - p.z};
	}

	double dist(P const &p) {
		return sqrt(pow(x - p.x,2) + pow(y - p.y,2) + pow(z - p.z,2));
	}
	void print() {cout << x << ";" << y << ";" << z << endl;}
};

vector<P> rotate2d(vector<P> const& v, vector<vector<int>> const& m) {
	vector<P> v_ret;
	for (auto const &p : v)
		v_ret.push_back(p.rotate(m));
	return v_ret;
}

bool offset_match(set<P> const& orig, vector<P> other, P offset)
{
	for (auto& p : other)
		p = p + offset;

	int count = 0;
	for (auto e_orig : orig) {
		for (auto e_other : other) {

			if (e_other == e_orig)
				count ++;
		}
	}

	// need more
	return count >= 12;
};

int main() {
	auto rot = rot3d();
	vector<vector<P>> v_raw;
	vector<P>* cur;
	string s;
	while (getline(cin,s)) {
		if (s.empty()) continue;
		if (s.back() == '-') {
			v_raw.push_back({});
			cur = &v_raw.back();
			continue;
		}
		cur->push_back({});
		sscanf(s.c_str(), "%d,%d,%d",&cur->back().x,&cur->back().y,&cur->back().z);
	}

	// easier for vector to pop back
	set<P> v_final;
	for (auto x : v_raw.front()) {
		auto info = v_final.insert(x);
	}

	v_raw.erase(v_raw.begin());
	auto it = v_raw.begin();

	P offset;
	vector<P> v_rot, v_offset;
	while (true) {

		for (it = v_raw.begin(); it != v_raw.end(); it++) {
			for (auto const &r : rot) {
				
				// rotated copy of raw
				v_rot = rotate2d(*it, r);

				// go through all pairs of point;
				for (auto e_final : v_final) {
					for (auto e : v_rot) {
						offset = e_final - e;
						if (offset_match(v_final, v_rot, offset))
							goto restart;
					}
				}
			}
		}

		restart:
		for (auto p : v_rot) {
			p = p + offset;
			v_final.insert(p);
			v_offset.push_back(offset);
		}
		v_raw.erase(it);
		if (v_raw.size() == 0) break;
	}
	cout << "beacons:" << v_final.size() << endl;



	


	
	





	// Rotate point;
	// If the axes 


//	cur = &v.front();
//	P p;
//	int count;
//	for (int i = 1; i < v.size(); i++) {
//		count = 0;
//		for (auto orig : *cur) {
//			for (auto other : v[i]) {
//				for (auto r : rot) {
//					if (orig == other.rotate(r))
//						count++;
//				}
//			}
//		}
//		if (count >= 12 ) {
//			cout << i << ": " << "works i guess" << endl;
//			cout << count << endl;
//		}
//	}
	return 0;
}
