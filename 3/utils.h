
#ifndef __UTILS_H__
#define __UTILS_H__

#include <vector>
#include <string>
#include <iostream>

long count_trees(const std::vector<std::string>& holder, int slope_x, int slope_y)
{
	int x = 0;
	int counter = 0;
	char tree = '#';
	for (int i = 0; i < holder.size(); i += slope_y)
	{
		if (holder[i][x % holder[0].size()] == tree) counter++;
		x += slope_x;
	}
	return counter;
}

#endif


