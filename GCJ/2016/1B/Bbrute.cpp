#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <utility>
#include <functional>
#include <queue>
#include <string>
#include <sstream>
#include <cmath>
#include <cctype>
using namespace std;

void solve(string& sc, string& sj)
{
	string resc, resj;
	int dist = 2000000000;
	int limit = 10, test = 1;
	while(++test <= sc.size())
		limit *= 10;

	for(int i = 0; i < limit; ++i)
	{
		string s1 = to_string(i);
		while(s1.size() < sc.size())
			s1 = '0' + s1;

		for(int j = 0; j < limit; ++j)
		{
			string s2 = to_string(j);
			while(s2.size() < sc.size())
				s2 = '0' + s2;

			bool isMatch = true;
			for(int k = 0; isMatch && k < (int)sc.size(); ++k)
			{
				if(sc[k] != '?' && sc[k] != s1[k]) isMatch = false;
				if(sj[k] != '?' && sj[k] != s2[k]) isMatch = false;
			}

			if(isMatch)
			{
				int tmp = (i < j ? j-i : i-j);
				if(tmp < dist)
				{
					dist = tmp;
					resc = s1, resj = s2;
				}	
			}
		}
	}
	sc = resc;
	sj = resj;
}


int main()
{
	int T; 
	cin >> T;

	for(int t = 1; t <= T; ++t)
	{	
		string C, J, resc1, resc2, resj1, resj2;	
		cin >> C >> J;

		solve(C, J);

		cout << "Case #" << t << ": " << C << " " << J << endl;

	}

}