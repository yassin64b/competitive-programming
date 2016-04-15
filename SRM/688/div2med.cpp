#include <vector>
#include <string>

using namespace std;

class ParenthesesDiv2Medium
{
public:
	vector<int> correct(string s)
	{
		vector <int> v;
		int cnt = 0, n = (int)s.size();
		
		for(int i = 0; i < n; ++i)
		{
			if(s[i] == '(')
			{
				if(cnt > (n-i)/2)
				{
					v.push_back(i);
					--cnt;
				}
				else 
					++cnt;
			}
			else
			{
				if(cnt == 0)
				{
					v.push_back(i);
					++cnt;
				}
				else
					--cnt;
			}
		}
		return v;
	}
};