#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>
#include <iterator>
#include <stack>
#include <string>
#include "../util.h"
using namespace std;
#define IN_MIN 1
int inline pix(char c) { return c == '.' ? 0 : 1;}

int main() 
{
	string img_algo,s;
	vector<string> img;
	deque<deque<char>> img_input,img_output;
	ll yn_in,yn_out,xn_in,xn_out;
	ll b,idx,count = 0, count_dots = 0;
	bool left, right, up, down, center, leftup, rightup, leftdown, rightdown;
	auto f = [](int y, int x, int yn_in, int xn_in)
	{
		return 0 <= x && 0 <= y && x < xn_in && y < yn_in;
	};
	getline(cin,img_algo);
	getline(cin,s);
	while (getline(cin,s))
		img.push_back(s);
	vector<bool> bin(9);
	yn_in = img.size(), xn_in = img[0].size();
	img_input = deque<deque<char>>(yn_in, deque<char>(xn_in,'.'));

	for (int y = 0; y < yn_in; y++) {
		for (int x = 0; x < xn_in; x++) {
			img_input[y][x] = img[y][x];
		}
	}
	
	bool dark = true;
	char around;
	while (count < 2) {
		around = dark ? '.' : '#';
		dark = !dark;
		yn_in = img_input.size(), xn_in = img_input[0].size();

		img_output = deque<deque<char>>(yn_in, deque<char>(xn_in,around));
		for (auto& xx : img_output) {
			xx.push_front(around);
			xx.push_back(around);
		}

		img_output.push_front(deque<char>(img_output[0].size(),around));
		img_output.push_back(deque<char>(img_output[0].size(),around));
		yn_out = img_output.size(), xn_out = img_output[0].size();


		for (int y = 0; y < yn_out; y++) {
			for (int x = 0; x < xn_out; x++) {
				idx = 0;

				y -= IN_MIN;
				x -= IN_MIN;

				up = f(y - 1,x,yn_in,xn_in);
				down = f(y + 1,x,yn_in,xn_in);
				left = f(y,x-1,yn_in,xn_in);
				right = f(y,x+1,yn_in,xn_in);

				center = f(y,x,yn_in,xn_in);

				leftup = f(y-1,x-1,yn_in,xn_in);
				rightup = f(y-1,x+1,yn_in,xn_in);
				leftdown = f(y+1,x-1,yn_in,xn_in);
				rightdown = f(y+1,x+1,yn_in,xn_in);


				bin[idx] = pix(leftup ? img_input[y-1][x-1] : around);
				idx++;

				bin[idx] = pix(up ? img_input[y-1][x] : around);
				idx++;

				bin[idx] = pix(rightup ? img_input[y-1][x+1] : around);
				idx++;

				bin[idx] = pix(left ? img_input[y][x-1] : around);
				idx++;

				bin[idx] = pix(center ? img_input[y][x] : around);
				idx++;

				bin[idx] = pix(right ? img_input[y][x+1] : around);
				idx++;

				bin[idx] = pix(leftdown ? img_input[y+1][x-1] : around);
				idx++;

				bin[idx] = pix(down ? img_input[y+1][x] : around);
				idx++;

				bin[idx] = pix(rightdown ? img_input[y+1][x+1] : around);
				idx++;

				y += IN_MIN;
				x += IN_MIN;
				
				b = binary(bin.begin(),bin.end());
				img_output[y][x] = img_algo[b];
			}
		}

		img_input.swap(img_output);
		count++;
	}

	count_dots = 0;
	for (auto xx : img_input) {
		for (auto xxx : xx) {
			count_dots += pix(xxx);
		}
	}
	cout << count_dots << endl;
	

	return 0;
}
