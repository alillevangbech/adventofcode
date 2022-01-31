#include <bits/stdc++.h>
#include <stack>
#include "../util.h"
using namespace std;
#define RANGE 50
void velocity(ll &x_cur, ll &y_cur, ll x, ll y);
void drag(ll &x_cur);
void gravity(ll &y_cur);

int main() 
{
	ll x_min, x_max, y_min, y_max;
	ll x_cur, y_cur, x_vel, y_vel, x_vel_orig, y_vel_orig;
	bool hit = true;
	cin >> x_min >> x_max >> y_min >> y_max;
	ll range = y_min * 5 * -1;
	// cout << range << endl;
	ll highy = 0, highy_tmp = 0;
	ll count = 0;
	for (int y = -1*range; y <= range; y++) {
		for (int x = 1; x <= x_max ; x++) {
			hit = false;
			x_vel_orig = x;
			y_vel_orig = y;
			x_vel = x_vel_orig;
			y_vel = y_vel_orig;
			x_cur = 0;
			y_cur = 0;
			highy = 0;
			while (y_cur >= y_min) {
	//			cout << x_cur << ";" << y_cur << endl;
				velocity(x_cur, y_cur, x_vel, y_vel);
				drag(x_vel);
				gravity(y_vel);
				highy = max(highy, y_cur);
				if (x_min <= x_cur && x_cur <= x_max &&
					y_min <= y_cur && y_cur <= y_max) {
					count++;
					//cout << "hit: " << x << ";" << y << "|" << highy << endl;
					highy_tmp = max(highy, highy_tmp);
					hit = true;
					break;
				}
			}
		}
	}
	cout << count << endl;
	return 0;
}


void velocity(ll &x_cur, ll &y_cur, ll x, ll y) {
	x_cur += x;
	y_cur += y;
}
void drag(ll &x_cur) {
	if (x_cur > 0)
		x_cur--;
}
void gravity(ll &y_cur) {
	y_cur--;
}
