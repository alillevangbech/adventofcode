
#ifndef __UTILS_H__
#define __UTILS_H__

#include <string>
#include <algorithm>

std::string password(const std::string& s)
{
	std::string s1 = ": ";
	return s.substr(s.find(s1) + s1.length());
}


char password_char(const std::string& s)
{
	std::string s1 = ": ";
	return s[s.find(s1)-1];
}

void getLimits(const std::string& s, int* lower, int* upper)
{
	size_t space = s.find(' ');
	size_t binde = s.find('-');
	(*lower) = std::stoi(s.substr(0,binde));
	(*upper) = std::stoi(s.substr(binde+1,space));
}
#endif


