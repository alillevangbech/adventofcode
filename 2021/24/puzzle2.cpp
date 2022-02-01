#include <bits/stdc++.h>
#include <functional>
#include "../util.h"
using namespace std;
#define LEN 14
#define MONAD_MAX 9
#define MONAD_MIN 1
enum IN {
	INP,ADD,MUL,DIV,MOD,EQL
};
struct ALU {
	IN a;
	char v1,v2;
	int i;
	bool thirdword, isnumber;
};

void test(vector<vector<ALU>> in);
void debug(vector<vector<ALU>> in);
ALU parse(string s);

/* 
 * after a lot of botching it up - just reverse engineer by hand.
 * basically just a stack in assembly
 * */

int main() 
{
	unordered_map<char, int> umap, umap_tmp; 
	string s, s_tmp, num;
	vector<vector<ALU>> in;
	while (getline(cin,s)) {
		ALU alu = parse(s);
		if (alu.a == INP) {
			in.push_back({});
		}
		in.back().push_back(alu);
	}

	debug(in);
	return 0;
}


void test2(vector<vector<ALU>> in) {
	
	int z,w,y,x;
	vector<function<ll(ll)>> v;

	auto f_up = [=](ll w) -> ll {
		ll _z = z;
		ll _w = w;
		ll _y = y;
		ll _x = x;

		_z *= 26;
		_z += _w;
		_z += _y;
		return _z;
	};

	auto f_down = [=](ll w, ll &z, ll y, ll x) -> ll {
		ll _z = z;
		ll _w = w;
		ll _y = y;
		ll _x = x;

		_x = _z;
		_x %= 26;
		_z /= 26;
		_x += _x;

		if (_x == _w)
			return _z;
		else
			return _z;
	};


	for (auto vin : in) {
		for (int i = 0; i < vin.size(); i++) {
			bool up;
			switch (i) {
				case 4:
					up = vin[i].i != 1;
					break;
				default:
					break;
			}
		}
	}

};



void test(vector<vector<ALU>> in) {
	unordered_map<char, ll> umap, umap_tmp;
	map<int,unordered_map<char,ll>> mem;
	int a,b,x,idx = 0;
	bool back = false;
	umap = {{'w',0},{'x',0},{'y',0},{'z',0}};
	for (int i = 0; i < in.size(); i++) {
		mem[i] = umap;
		for (int j = 0; j < in[i].size(); j++) {
			auto ptr = in[i][j];
			switch (ptr.a) {
				case INP:
					umap[ptr.v1] = MONAD_MAX;
					idx++;
					break;
				case ADD:
					a = umap[ptr.v1];
					b = ptr.isnumber ? ptr.i : umap[ptr.v2];
					umap[ptr.v1] = a + b;
					break;
				case MUL:
					a = umap[ptr.v1];
					b = ptr.isnumber ? ptr.i : umap[ptr.v2];
					umap[ptr.v1] = a * b;
					break;
				case DIV:
					a = umap[ptr.v1];
					b = ptr.isnumber ? ptr.i : umap[ptr.v2];
					back = b != 1;
					umap[ptr.v1] = a / b;
					break;
				case MOD:
					a = umap[ptr.v1];
					b = ptr.isnumber ? ptr.i : umap[ptr.v2];
					umap[ptr.v1] = a % b;
					break;
				case EQL:
					if (ptr.v2 == 'w')
						cout << umap['x'] << endl;
					a = umap[ptr.v1];
					b = ptr.isnumber ? ptr.i : umap[ptr.v2];
					umap[ptr.v1] = a == b;
					break;
				default:
					break;
			}
		}
		cout << endl;
		printf("z : %ld\n", umap['z']);
	}
}

void debug(vector<vector<ALU>> in) {
	for (auto vin : in) {
		for (int i = 0; i < vin.size(); i++) {
			switch (i) {
				case 4:
				case 14:
				case 15:
					if (vin[i].isnumber) 
						cout << vin[i].i << "\t";
					else
						cout << vin[i].v2 << "\t";
				default:
					break;
			}
		}
		cout << endl;
	}
}

ALU parse(string s) {
		ALU ptr;
		size_t f;
		string s_tmp;

		f = s.find_first_of(' ');
		s_tmp = s.substr(0,f);
		if (s_tmp == "inp") {
			ptr.a = INP;
		} else if (s_tmp == "add") {
			ptr.a = ADD;
		} else if (s_tmp == "mul") {
			ptr.a = MUL;
		} else if (s_tmp == "div") {
			ptr.a = DIV;
		} else if (s_tmp == "mod") {
			ptr.a = MOD;
		} else if (s_tmp == "eql") {
			ptr.a = EQL;
		} else {
			printf("fuck %s\n", s_tmp.c_str());
		}
		ptr.v1 = s[f+1];
		ptr.thirdword = std::count(s.begin(), s.end(), ' ') == 2;
		ptr.v2 = '-';
		if (ptr.thirdword) {
			f =	s.find_last_of(' ');
			s_tmp = s.substr(f+1);
			ptr.isnumber = is_number(s_tmp);
			if (ptr.isnumber)
				ptr.i = stoi(s_tmp);
			else 
				ptr.v2 = s_tmp[0];
		}
	return ptr;
}
