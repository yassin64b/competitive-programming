#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

class MultiplicationTable2Easy
{
public:
	string isGoodSet(vector<int> table, vector<int> t)
	{
		int n = (int) sqrt(table.size());
		for(int i = 0; i < t.size(); ++i)
		{
			for(int j = 0; j < t.size(); ++j)
			{
				if(find(t.begin(), t.end(), table[t[i]*n+t[j]]) == t.end())
					return "Not Good";
			}
		}
		return "Good";
	}
};