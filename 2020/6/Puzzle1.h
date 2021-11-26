
#ifndef __PUZZLE_1_H__
#define __PUZZLE_1_H__ 

#include "utils.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <regex>

using namespace std;



void first_puzzle()
{
	std::cout << " ################ PUZZLE ONE ################\n\n " << std::endl;
	ifstream ifile ("./input.txt");
	std::filebuf* pbuf = ifile.rdbuf();
	size_t bufsize = pbuf->pubseekoff(0,ifile.end,ifile.in);
	pbuf->pubseekpos(0,ifile.in);
	char* raw_data = new char[bufsize];
	pbuf->sgetn(raw_data,bufsize);
	std::string data = std::string(raw_data);
	
	vector<string> grp;

	std::string splitter = "\n\n",tmpdata;
	size_t split;
	while (split != std::string::npos)
	{
		split = data.find(splitter);
		tmpdata = data.substr(0,split);
		simple_split_vector(grp,tmpdata,'\n');
		data = data.substr(split + splitter.length());
	}


	string alph = alphabet();
	vector<bool> result (alph.size());
	int count = 0;
	for (int i = 0; i < grp.size(); i++)
	{
		reset_vector(result);
		for (int k = 0; k < alph.size(); k++)
		{
			if (grp[i].find(alph[k]) != std::string::npos) result[k] = true;
		}
		count += count_vector(result);
	}
	
	delete[] raw_data;
	cout << count;
	ifile.close();
}
#endif
