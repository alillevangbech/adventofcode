#include <algorithm>
#include <bits/stdc++.h>
#include "../util.h"
using namespace std;

/*
 *	rules
 *  1. You can't stop on spaces outside rooms
 *  2. You can't move into a room, which is not your own room, unless you start there.
 *  3. When moving into the hallway, your next move must be in into a room
 */

/*
Just do it by hand.
#############
#...........#
###A#B#C#D###
  #A#B#C#D#
  #########
*/
void move_in();
void move_out();

int main() 
{
	auto bp = read_input();
	ll xn = bp[0].size(), yn = bp.size();
	for (auto &v : bp) {
		if (v.size() != xn) {
			replace(v.begin(),v.end(), ' ', '#');
			v.push_back('#');
			v.push_back('#');
		}
	}
	print_input(bp);
	return 0;
}

/*
 *
 >>> sum = 0
 >>> sum += 9
 >>> sum += 40
 >>> sum += 7
 >>> sum += 600
 >>> sum += 7000
 >>> sum += 8000
 >>> sum += 500
 >>> sum += 60
 >>> sum += 60
 >>> sum += 3
 >>> sum += 3
 *
 *
 *
 *
 *
 *
 *
 */
