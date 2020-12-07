
#ifndef __UTILS_H__
#define __UTILS_H__
using namespace std;
#include <vector>
#include <string>


int binary(string s, char clower, char cupper, int lower, int upper)
{
	int tmpupper = upper;
	int tmplower = lower;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == cupper)
		{
			tmpupper = (tmplower+tmpupper)/2;
		}
		else if (s[i] == clower)
		{
			tmplower = (tmplower+tmpupper)/2 + 1;
		}
	}
	return tmpupper == tmplower ? tmplower : -1;
}

int seat_id(const std::string& bp)
{
	int rows = 128 - 1;
	int cols = 8 - 1;

	int myrow = binary(bp.substr(0,7),'B','F',0,rows);
	int mycol = binary(bp.substr(7),'R','L',0,cols);
		
	return myrow*8+mycol;
}
#endif


