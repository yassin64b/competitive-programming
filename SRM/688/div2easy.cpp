#include <string>

using namespace std;

class ParenthesesDiv2Easy
{
public:
	int getDepth(string s)
	{
		int cnt = 0, depth = 0;
		
		for(char c: s)
		{
			if(c == '(')
			{
				++cnt;
				if(cnt > depth)
					depth = cnt;
			}
			else
					--cnt;
		}
		return depth;
	}
};