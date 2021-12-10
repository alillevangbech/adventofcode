#include <bits/stdc++.h>
#include <stack>
#include "../util.h"
using namespace std;
#define S1 1;
#define S2 2;
#define S3 3;
#define S4 4;

enum _state {
	LEGAL,
	INCOMPLETE,
	ILLEGAL,
};

int main() 
{
	auto input = read_input();
	// for (auto& r : input) cout << r << endl;
	stack<char> s; /* () */
	auto clear = [](stack<char>& s) { while(!s.empty()) s.pop(); };
	ll sum = 0, tmp_sum = 0;
	vector<ll> sums;
	_state state;
	char tmp = '\0';
	for (const auto& line : input) {
		state = LEGAL;
		for (auto c : line) {
			switch (c) {
				case '<':
				case '{':
				case '[':
				case '(':
		//			cout << c << endl;
					s.push(c);
					break;
				case ')':
					tmp = s.top();
					//cout << s.top() << ";" << c << ";" << s.size() << endl;
					if (tmp == '(') {
						s.pop();
					} else {
						state = ILLEGAL;
					}
					break;
				case ']':
					//cout << s.top() << ";" << c << ";" << s.size() << endl;
					tmp = s.top();
					if (tmp == '[') {
						s.pop();
					} else {
						state = ILLEGAL;
					}
					break;
				case '}':
					//cout << s.top() << ";" << c << ";" << s.size() << endl;
					tmp = s.top();
					if (tmp == '{') {
						s.pop();
					} else {
						state = ILLEGAL;
					}
					break;
				case '>':
					//cout << s.top() << ";" << c << ";" << s.size() << endl;
					tmp = s.top();
					if (tmp == '<') {
						s.pop();
					} else {
						state = ILLEGAL;
					}
					break;
				default:
					cout << "fuck" << endl;
					break;
			}
			if (state == ILLEGAL)
				break;
			//EOL
		}
		if (state == LEGAL && !s.empty())
			state = INCOMPLETE;

		if (state == ILLEGAL || state == LEGAL)
			clear(s);
		else {
	//		cout << line << " INCOMPLETE " << endl;
			tmp_sum = 0;
			while (!s.empty()) {
				switch (s.top()) {
					case '(':
						tmp_sum = 5*tmp_sum + S1;
						break;
					case '[':
						tmp_sum = 5*tmp_sum + S2;
						break;
					case '{':
						tmp_sum = 5*tmp_sum + S3;
						break;
					case '<':
						tmp_sum = 5*tmp_sum + S4;
						break;
					default:
						cout << "fuck" << endl;
						break;
				}
				s.pop();
			}
			sums.push_back(tmp_sum);
		}
	}
	sort(begin(sums), end(sums));
	// for (auto x : sums) cout << x << endl;
	cout << sums[sums.size()/2] << endl;
	return 0;
}
