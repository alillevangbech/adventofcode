typedef long long ll;
typedef unsigned long long ull;

#define toRadian(x) x*M_PI/180L
#define toDegree(x) x*180L/M_PI

inline bool _EOF() {return (std::cin >> std::ws).eof(); }
ll binary(const std::vector<bool>& v)
{return std::accumulate(rbegin(v),rend(v),0,
	[](auto x, auto y) {return (x << 1) + y;});}

inline std::vector<std::string> read_input()
{
	std::string line;
	std::vector<std::string> v;
	while (std::getline(std::cin, line)) v.push_back(line);
	return v;
}

inline void print_input(const std::vector<std::string>& input)
{
	for (auto x : input) {
		std::cout << x << std::endl;
	}
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

int CalcDeterminant(std::vector<std::vector<int>> Matrix)
   {
        //this function is written in c++ to calculate the determinant of matrix
        // it's a recursive function that can handle matrix of any dimension
        int det = 0; // the determinant value will be stored here
        if (Matrix.size() == 1)
        {
            return Matrix[0][0]; // no calculation needed
        }
        else if (Matrix.size() == 2)
        {
            //in this case we calculate the determinant of a 2-dimensional matrix in a 
            //default procedure
            det = (Matrix[0][0] * Matrix[1][1] - Matrix[0][1] * Matrix[1][0]);
            return det;
        }
        else
        {
            //in this case we calculate the determinant of a squared matrix that have 
            // for example 3x3 order greater than 2
            for (int p = 0; p < Matrix[0].size(); p++)
            {
                //this loop iterate on each elements of the first row in the matrix.
                //at each element we cancel the row and column it exist in
                //and form a matrix from the rest of the elements in the matrix
				std::vector<std::vector<int>> TempMatrix; // to hold the shaped matrix;
                for (int i = 1; i < Matrix.size(); i++)
                {
                    // iteration will start from row one cancelling the first row values
					std::vector<int> TempRow;
                    for (int j = 0; j < Matrix[i].size(); j++)
                    {
                        // iteration will pass all cells of the i row excluding the j 
                        //value that match p column
                        if (j != p)
                        {
                           TempRow.push_back(Matrix[i][j]);//add current cell to TempRow 
                        }
                    }
                    if (TempRow.size() > 0)
                        TempMatrix.push_back(TempRow);
                    //after adding each row of the new matrix to the vector tempx
                    //we add it to the vector temp which is the vector where the new 
                    //matrix will be formed
                }
                det = det + Matrix[0][p] * pow(-1, p) * CalcDeterminant(TempMatrix);
                //then we calculate the value of determinant by using a recursive way
                //where we re-call the function by passing to it the new formed matrix
                //we keep doing this until we get our determinant
            }
            return det;
        }
};

std::vector<std::vector<std::vector<int>>> rot3d()
{
	int n = 3;
	int i;
	std::vector<std::vector<std::vector<int>>> rotations;
	std::vector<std::vector<int>> uniq;
	std::vector<int> v(n,0);

	for (auto &a : v) {
		for (i=-1;i<=1;i+=2) {
			a = i;
			uniq.push_back(v);
			a = 0;
		}
	}

	for (auto row1 : uniq) {
		for (auto row2: uniq) {
			for (auto row3: uniq) {
				bool ok = true;
				for (i = 0; i < n; i++) {
					if (abs(row1[i]) + abs(row2[i]) + abs(row3[i]) != 1)
						ok = false; 
				}
				if (ok) {
					rotations.push_back({});
					rotations.back().push_back(row1);
					rotations.back().push_back(row2);
					rotations.back().push_back(row3);
					int det = CalcDeterminant(rotations.back());
					if (det < 0) 
						rotations.pop_back();
				}
			}
		}
	}
	return rotations;
}
