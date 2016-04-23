#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <utility>
#include <sstream>

using namespace std;

typedef long long lli;
typedef pair<int,int> pii;

class BadNeighbors
{
public:
	int maxDonations(vector<int> don)
	{
		int N = (int) don.size();
		vector<pii> dp(N);

		for(int i = 0; i < N; ++i)
			dp[i] = make_pair(don[i], 0);

		dp[0].second = 1;

		for(int i = 2; i < N; ++i)
		{
			int nmax = 0, first = 0;
			for(int j = 0; j < i-1; ++j)
			{
				if(i == N-1 && dp[j].second == 1)
				{
					if(dp[i].first > dp[0].first)
						nmax = dp[j].first-dp[0].first, first = 0;
				}
				else if(dp[j].first > nmax)
					nmax = dp[j].first, first = dp[j].second;
			}	

			dp[i].first += nmax, dp[i].second = first;
			//cout << i << " : " << dp[i].first << endl;
		}

		int res = 0;

		for(int i = 0; i < N; ++i)
			res = max(res, dp[i].first);

		return res;
	}

};

/*int main()
{
	BadNeighbors b;

	cout << b.maxDonations({10,3,2,5,7,8}) << endl;
	cout << b.maxDonations(	{ 11, 15 }) << endl;
	cout << b.maxDonations({7, 7, 7, 7, 7, 7, 7}) << endl;
	cout << b.maxDonations({1, 2, 3, 4, 5, 1, 2, 3, 4, 5}) << endl;
	cout << b.maxDonations({94, 40, 49, 65, 21, 21, 106, 80, 92, 81, 679, 4, 61,  
  			6, 237, 12, 72, 74, 29, 95, 265, 35, 47, 1, 61, 397,
  			52, 72, 37, 51, 1, 81, 45, 435, 7, 36, 57, 86, 81, 72});
}*/