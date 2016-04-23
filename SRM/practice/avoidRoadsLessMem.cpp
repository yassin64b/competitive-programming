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

class AvoidRoads
{
public:
	lli numWays(int width, int height, vector<string> bad)
	{
		lli dp[101][101] = {0}; 
		bool inv[101][101] = {0};

		int a, b, c, d;
		for(string& s: bad)
		{
			stringstream ss(s);
			ss >> a >> b >> c >> d;

			inv[a][b] = true, inv[c][d] = true;
		}

		dp[0][0] = 1;
		for(int i = 1; i < width+1; ++i)
		{
			if(inv[i][0] && inv[i-1][0]) break;
			dp[i][0] = 1;
		}
		for(int j = 1; j < width+1; ++j)
		{
			if(inv[0][j] && inv[0][j-1]) break;
			dp[0][j] = 1;
		}

		for(int i = 1; i < width+1; ++i)
		{
			for(int j = 1; j < height+1; ++j)
			{	
				if(!inv[i][j] || !inv[i-1][j])
					dp[i][j] += dp[i-1][j];
				if(!inv[i][j] || !inv[i][j-1])
					dp[i][j] += dp[i][j-1];
			}
		}

		/*for(int i = 0; i < width+1; ++i)
		{
			for(int j = 0; j < height+1; ++j)
				cout << dp[i][j] << " ";
			cout << endl;
		}*/

		return dp[width][height];
	}

};

/*int main()
{
	int w, h;
	cin >> w >> h;

	AvoidRoads av;
	cout << av.numWays(w, h, {}) << endl;
	
	return 0;
}*/