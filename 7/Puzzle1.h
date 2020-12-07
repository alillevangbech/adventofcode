
#ifndef __PUZZLE_1_H__
#define __PUZZLE_1_H__ 

#include "utils.h"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;


void first_puzzle()
{
	std::cout << " ################ PUZZLE ONE ################\n\n " << std::endl;
	ifstream ifile ("./input.txt");
	std::string line;
	std::vector<bag> holder;

	while (std::getline(ifile,line))
	{
		holder.push_back(parseBag(line));
	}

	int count = 0;
	string targetBag = "shiny gold";
	for (int i = 0; i < holder.size(); i++)
	{
		cout << "index: " << i << endl;
		count += searchBag(holder,holder[i],targetBag);	
	}
	cout << holder.size() << endl;
	cout << "count: " << count;
	ifile.close();
}
#endif
