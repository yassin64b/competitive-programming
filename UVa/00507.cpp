#include <iostream>
#include <vector>
#include <cstdlib>
#include <limits>
using namespace std;

int main()
{
	int b;
	cin >> b;

	for(int i = 0; i < b; ++i)
	{
		int s; 
		cin >> s;
		vector<int> v(s-1);
		for(int i = 0; i < s-1; ++i)
			cin >> v[i];

		vector<int> dp(s, 0);
		int maxv = numeric_limits<int>::min();
		for(int i = 1; i < s; ++i)
		{
			dp[i] = max((dp[i-1]==-1 ? 0 : dp[i-1])+v[i-1], -1);
			maxv = max(maxv, dp[i]);
		}

		if(maxv < 0)
		{
			cout << "Route " << i+1 << " has no nice parts" << endl;
			continue;
		}	

		int ri = 0, rj = 0, cnt = 0;
		for(int i = s-1; i >= 1; --i)
		{	
			if(dp[i] != maxv) continue;
			int j = i;
			cnt = 0;
			while(i >= 1 && dp[i] >= 0)
				--i, ++cnt;
			
			//cout << "i, j: " << i << '\t' << j << endl;
			if(j-i >= rj-ri)
				rj = j, ri = i;
		}
		
		cout << "The nicest part of route " << i+1 << " is between stops " << ri+1 << " and " << rj+1 << endl;			
	}
}