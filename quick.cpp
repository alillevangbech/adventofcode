


#include <iostream>
#include <fstream>
#include <string>
int main()
{
	std::fstream ifile;
	std::ofstream ofile;
	std::string line;
	std::string search = "main.o:";
	std::string replace = "main.o: Puzzle1.h Puzzle2.h";
	for (int i = 1; i < 2; i++)
	{
		std::string ipath = "./" + std::to_string(i) + "/makefile";
		std::string opath = "./" + std::to_string(i) + "/makefile_demo";
		ifile = std::fstream(ipath);
		ofile = std::ofstream(opath);

		while (!ifile.eof())
		{
			std::getline(ifile,line);
			int spot = line.find(search);
			if (spot >= 0)
			{
				std::string tmpstring = line.substr(0,spot);
				tmpstring += replace_string;
				tmpstring += line.substr(spot+search.length(),line.length());
				 
			}
	}
}
