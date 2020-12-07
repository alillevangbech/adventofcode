#ifndef __PUZZLE_2_H__
#define __PUZZLE_2_H__

#include "utils.h"
#include <iostream>
#include <fstream>
#include <regex>

void second_puzzle()
{
	std::cout << "\n\n ############### SECOND PUZZLE ##############\n\n" << std::endl;
	
	std::ifstream ifile("./input.txt");
	std::filebuf* pbuf = ifile.rdbuf();
	std::size_t bufSize = pbuf->pubseekoff(0,ifile.end,ifile.in);
	pbuf->pubseekpos(0,ifile.in);
	char* raw_data = new char[bufSize];
	pbuf->sgetn(raw_data,bufSize);
	std::string data = std::string(raw_data);
	std::string tmpdata;
	std::string splitter = "\n\n";
	std::vector<std::map<std::string,std::string>> holder;
	std::map<std::string,std::string> map;
	size_t split = 0;
	while (split != std::string::npos)
	{
		split = data.find(splitter);
		tmpdata = data.substr(0,split);
		split_into_vector(map,tmpdata,' ','\n');
		holder.push_back(map);
		map.clear();
		data = data.substr(split + splitter.length());
	}
	

	auto byr = [] (std::string s) { return std::regex_match(s, std::regex("19[2-9]\\d|200[0-2]"));};
	auto iyr = [] (std::string s) { return std::regex_match(s, std::regex("201\\d|2020"));};
	auto eyr = [] (std::string s) { return std::regex_match(s, std::regex("202\\d|2030"));};
	auto hgt = [] (std::string s)
	{ return std::regex_match(s, std::regex("1[5-8]\\dcm|19[0-3]cm|59in|6\\din|7[0-6]in"));};
	auto hcl = [] (std::string s) { return std::regex_match(s, std::regex("#[0-9a-f]{6}"));};
	auto ecl = [] (std::string s)
	{ return std::regex_match(s, std::regex("amb|blu|brn|gry|grn|hzl|oth"));};
	auto pid = [] (std::string s) { return std::regex_match(s, std::regex("\\d{9}"));};

	int count = 0;
	std::vector<std::string> req {"byr","iyr","eyr","hgt","hcl","ecl","pid"};
	std::vector<bool> record(req.size());
	for (int i = 0; i < holder.size(); i++)
	{
		reset_vector(record);
		for (int j = 0; j < req.size(); j++)
		{
			if (holder[i].find(req[j]) != holder[i].end()) 
			{
				record[j] = true; 
				switch (j) {
					
				case 0:
					  record[j] = byr(holder[i][req[j]]);
					  break;
				case 1:
					  record[j] = iyr(holder[i][req[j]]);
					  break;
				case 2:
					  record[j] = eyr(holder[i][req[j]]);
					  break;
				case 3:
					  record[j] = hgt(holder[i][req[j]]);
					  break;
				case 4:
					  record[j] = hcl(holder[i][req[j]]);
					  break;
				case 5:
					  record[j] = ecl(holder[i][req[j]]);
					  break;
				case 6:
					  record[j] = pid(holder[i][req[j]]);
					  break;
				}
			}
		}
		count += check_vector(record);
	}

	std::cout << count;

	ifile.close();
	delete[] raw_data;
}
#endif
