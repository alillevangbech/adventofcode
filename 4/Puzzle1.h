
#ifndef __PUZZLE_1_H__
#define __PUZZLE_1_H__ 

#include "utils.h"
#include <iostream>
#include <fstream>

void first_puzzle()
{
	std::cout << " ################ PUZZLE ONE ################\n\n " << std::endl;
	
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
	
	int count = 0;
	std::vector<std::string> req {"byr","iyr","eyr","hgt","hcl","ecl","pid"};
	std::vector<bool> record(req.size());
	for (int i = 0; i < holder.size(); i++)
	{
		reset_vector(record);
		for (int j = 0; j < req.size(); j++)
		{
			if (holder[i].find(req[j]) != holder[i].end()) record[j] = true;
		}
		count += check_vector(record);
	}

	std::cout << count;
	ifile.close();
	delete[] raw_data;
}




#endif
