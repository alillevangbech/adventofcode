
#ifndef __UTILS_H__
#define __UTILS_H__

#include <vector>
#include <string>
#include <iostream>
using namespace std;
struct bootcode
{
	std::string cmd;
	int arg;
};


bootcode parseBootcode(const std::string& s)
{
	bootcode b;
	int split = s.find(' ');
	b.cmd = s.substr(0,split);
	b.arg = std::stoi(s.substr(split));

	//std::cout << b.cmd << ": " << b.arg << endl;
	return b;
}

long accumBootcodes(const std::vector<bootcode>& holder)
{
	size_t len = holder.size();
	vector<bool> visitor (len,false);
	long accum = 0;
	int idx = 0;
	bootcode b;
	while (!visitor[idx])
	{
		b = holder[idx];
		visitor[idx] = true;
		
		if (b.cmd == "nop") idx++;
		else if (b.cmd == "jmp") idx += b.arg;
		else if (b.cmd == "acc")
		{	
			accum += b.arg;
			idx++;
		}
		else;

		if (idx == len) return accum;	
	}

	return accum;
}

long conqBootcodes(const std::vector<bootcode>& holder)
{
	size_t len = holder.size();
	vector<bool> visitor (len,false);
	long accum = 0;
	int idx = 0;
	bootcode b;
	while (!visitor[idx])
	{
		b = holder[idx];
		visitor[idx] = true;
		
		if (b.cmd == "nop") idx++;
		else if (b.cmd == "jmp") idx += b.arg;
		else if (b.cmd == "acc")
		{	
			accum += b.arg;
			idx++;
		}
		else;

		if (idx == len) return accum;	
	}

	return -1;
}

#endif


