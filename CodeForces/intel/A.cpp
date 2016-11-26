#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	int f;
	cin >> f;

	string t;
	cin >> t;

	int mincnt = 5;
	string res = t;
	if(f == 12)
	{
		for(char c = '0'; c <= '1'; ++c)
		{
			for(char d = '0'; d <= '9'; ++d)
			{
				if(d == '0' && c == '0') continue;
				if(c == '1' && d > '2') continue;
				int diff = (c != t[0]) + (d != t[1]);
				if(diff < mincnt)
				{
					mincnt = diff;
					res[0] = c, res[1] = d;
				}
			}
		}

	}
	else
	{
		for(char c = '0'; c <= '2'; ++c)
		{
			for(char d = '0'; d <= '9'; ++d)
			{
				if(c == '2' && d > '3') continue;
				int diff = (c != t[0]) + (d != t[1]);
				if(diff < mincnt)
				{
					mincnt = diff;
					res[0] = c, res[1] = d;
				}
			}
		}
	}
	mincnt = 5;
	for(char c = '0'; c <= '5'; ++c)
	{
		for(char d = '0'; d <= '9'; ++d)
		{
			int diff = (c != t[3]) + (d != t[4]);
			if(diff < mincnt)
			{
				mincnt = diff;
				res[3] = c, res[4] = d;
			}
		}
	}
	cout << res << endl;
}