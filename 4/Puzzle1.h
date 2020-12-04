
#ifndef __PUZZLE_1_H__
#define __PUZZLE_1_H__ 

#include "utils.h"
#include <iostream>
#include <fstream>
#include <string>
#include <type_traits>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>

void split_into_vector(std::vector<std::string>& holder, std::string s, char c)
{
	std::istringstream ss(s);
	while (std::getline(ss,s,c)) if (s != "") {holder.push_back(s);}
}

void reset_vector(std::vector<bool>& vec)
{
	for (auto i = vec.begin(); i != vec.end(); i++) *i = false;
}

bool check_vector(const std::vector<bool>& vec)
{
	for (auto i = vec.begin(); i != vec.end(); i++) if (!(*i)) return false;
	return true;
}

void first_puzzle()
{
	std::cout << " ################ PUZZLE ONE ################\n\n " << std::endl;
	std::ifstream ifile("./input.txt");
	std::string line,tmpline1,tmpline2,splitter = "\n\n";
	std::vector<std::vector<std::string>> holder;
	std::vector<std::string> passports;
	int count_lines = 0;
	int count_insert = 0;
	while (std::getline(ifile,line, ' '))
	{
		count_lines++;

		size_t split = line.find(splitter);
		if (split != std::string::npos)
		{
			tmpline1 = line.substr(0,split);
			tmpline2 = line.substr(split + splitter.length());
			
			split_into_vector(passports,tmpline1,'\n');
			holder.push_back(passports);
			count_insert++;
			passports.clear();

			split_into_vector(passports,tmpline2,'\n');
		}
		else
		{
			split_into_vector(passports,line,'\n');
		}
	}
	holder.push_back(passports); count_insert++;
	ifile.close();

	int count = 0;
	std::vector<std::string> req {"byr","iyr","eyr","hgt","hcl","ecl","pid"};
	std::vector<bool> record(req.size());
	for (int i = 0; i < holder.size(); i++)
	{
		reset_vector(record);
		for (int j = 0; j < holder[i].size(); j++)
		{
			std::cout << holder[i][j] << std::endl;
			for (int k = 0; k < req.size(); k++)
			{
				if (holder[i][j].find(req[k]) != std::string::npos) record[k] = true; 	
			}
		}
		std::cout << check_vector(record) << std::endl;	
		count += check_vector(record);
	}
	std::cout << holder.size() << std::endl;
	std::cout << count;
}
#endif
