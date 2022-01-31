#include <bits/stdc++.h>
#include <cstdio>
#include <iterator>
#include "../util.h"
using namespace std;

enum SLIME {
	EMPTY = 1 << 0,
	RIGHT = 1 << 1,
	DOWN = 1 << 2,
};

vector<SLIME> v;
vector<SLIME> v_tmp;
int nx;
int ny;

void getinput();
bool goright(int cur, int next);
bool godown(int cur, int next);
char translate(SLIME slime);
bool takestep();
void print();


//		putc(translate(v[i*nx +j]),stdout);
int main()
{
	getinput();
	int count = 1;
	while (!takestep()) count++;
	cout << count << endl;
	return 0;
}


bool takestep()
{
	int count = 0;
	int cur, nxt, i,j;
	for (i = 0; i < ny; i++) {
		for (j = 0; j < nx; j++) {
			cur = i*nx +j;
			if (v[cur] != RIGHT) continue;
			nxt = i*nx + (j == nx - 1 ? 0 : j + 1);
			//cout <<cur<<";"<<nxt<< endl;
			count += goright(cur,nxt);
		}
	}
	v = v_tmp;
	for (i = 0; i < ny; i++) {
		for (j = 0; j < nx; j++) {
			cur = i*nx +j;
			if (v[cur] != DOWN) continue;
			nxt = (i == ny - 1 ? 0 : i + 1)*nx + j;
			//cout <<cur<<";"<<nxt<< endl;
			count += godown(cur,nxt);
		}
	}
	v = v_tmp;
	return count == 0;
}


bool goright(int cur, int next)
{
	if (v[next] == EMPTY) {
		v_tmp[next] = RIGHT;
		v_tmp[cur] = EMPTY;
		return true;
	}
	return false;
}

bool godown(int cur, int next)
{
	if (v[next] == EMPTY) {
		v_tmp[next] = DOWN;
		v_tmp[cur] = EMPTY;
		return true;
	}
	return false;
}


char translate(SLIME slime) {
	switch (slime) {
	case EMPTY:
		return '.';
	case DOWN:
		return 'v';
	case RIGHT:
		return '>';
	default: exit(1);
	};
}

void print()
{
	int i,j;
	for (i = 0; i < ny; i++) {
		for (j = 0; j < nx; j++) {
			printf("%c", translate(v[i*nx +j]));
		}
		putc('\n',stdout);
	}
}

void getinput()
{
	auto input = read_input();
	nx = input[0].size();
	ny = input.size();

	for (auto line : input) {
		for (auto c : line) {
			switch (c) {
				case '.':
					v.push_back(EMPTY);
					break;
				case 'v':
					v.push_back(DOWN);
					break;
				case '>':
					v.push_back(RIGHT);
					break;
				default: exit(1);
			};
		}
	}
	v_tmp = v;
}
