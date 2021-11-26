#ifndef __PUZZLE_2_H__
#define __PUZZLE_2_H__

#include "utils.h"
#include <iostream>
#include <fstream>
#include <vector>

void second_puzzle()
{
	std::cout << "\n\n ############### SECOND PUZZLE ##############\n\n" << std::endl;
	
	ifstream ifile ("./input.txt",std::ios::in | std::ios::binary);
	std::filebuf* pbuf = ifile.rdbuf();
	size_t bufsize = pbuf->pubseekoff(0,ifile.end,ifile.in);
	pbuf->pubseekpos(0,ifile.in);
	char* raw_data = new char[bufsize];
	pbuf->sgetn(raw_data,bufsize);
	std::string data = std::string(raw_data,bufsize);
	vector<vector<string>> holder;
	vector<string> grp;
	
	std::string splitter = "\n\n",tmpdata;
	size_t split = 0;
	while (split != std::string::npos)
	{
		split = data.find(splitter);
		tmpdata = data.substr(0,split);
		split_into_vector(grp,tmpdata,'\n');
		holder.push_back(grp);
		grp.clear();
		data = data.substr(split + splitter.length());
	}

	string alph = alphabet();
	vector<int> result (alph.size());
	int count = 0;
	for (int i = 0; i < holder.size(); i++)
	{
		reset_vector(result);
		for (int j = 0; j < holder[i].size(); j++)
		{	
			for (int k = 0; k < alph.size(); k++)
			{
				if (holder[i][j].find(alph[k]) != std::string::npos) result[k]++;
			}
		}
		count += count_vector(result,holder[i].size());
	}
	cout << count;
	delete[] raw_data;
	ifile.close();
}

#endif
