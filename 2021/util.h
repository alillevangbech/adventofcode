inline bool _EOF() {return (std::cin >> std::ws).eof(); }

inline std::vector<std::string> read_input()
{
	std::string line;
	std::vector<std::string> v;
	while (std::getline(std::cin, line)) v.push_back(line);
	return v;
}


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
