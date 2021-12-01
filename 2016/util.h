inline std::vector<std::string> read_input()
{
	std::string line;
	std::vector<std::string> v;
	while (std::getline(std::cin, line)) v.push_back(line);
	return v;
}

inline void print_input(const std::vector<std::string>& v)
{
	for (auto s : v ) std::cout << s << std::endl;
}

using idx = int;
inline idx d2maxidx(idx max_x, idx max_y) {return max_x*(max_y-1) + max_x - 1;}
inline idx d2idx(idx x, idx y, idx max_x) {return max_x*y+x;}

inline void findPermutations(std::string str, int leftIndex, int rightIndex, std::vector<std::string>& v)
{
    if (leftIndex == rightIndex)
    {
		v.push_back(str);
    }
    else
    {
        for (int i = leftIndex; i <= rightIndex; i++)
        {
			std::swap(str[leftIndex], str[i]);
            findPermutations(str, leftIndex+1, rightIndex, v);
            //backtrack
			std::swap(str[leftIndex], str[i]);
        }
    }
}

inline bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && (std::isdigit(*it) || *it == '-')) ++it;
    return !s.empty() && it == s.end();
}
