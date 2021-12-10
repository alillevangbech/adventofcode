#include <bits/stdc++.h>
#include <stack>
#include "../util.h"
using namespace std;
#define S1 3;
#define S2 57;
#define S3 1197;
#define S4 25137;

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
	ll sum = 0;
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
			if (state == ILLEGAL) {
				switch (c) {
					case ')':
						sum += S1;
						break;
					case ']':
						sum += S2;
						break;
					case '}':
						sum += S3;
						break;
					case '>':
						sum += S4;
						break;
					default:
						cout << "fuck" << endl;
						break;
				}
				break;
			}
			//EOL
		}
		clear(s);
	}
	cout << sum << endl;
	return 0;
}
