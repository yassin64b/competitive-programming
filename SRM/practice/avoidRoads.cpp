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
		lli dp[101][101][2] = {0}; //dp[i][j][1] is flag bit for invalid path
		//expensive flag (long long) also makes code less clear

		int a, b, c, d;
		for(string& s: bad)
		{
			stringstream ss(s);
			ss >> a >> b >> c >> d;

			dp[a][b][1] = -1;
			dp[c][d][1] = -1;
		}

		//initialize border of grid with ones
		//stop at invalid path
		dp[0][0][0] = 1;
		for(int i = 1; i < width+1; ++i)
		{
			if(dp[i][0][1] == -1 && dp[i-1][0][1] == -1) break;
			dp[i][0][0] = 1;
		}
		for(int j = 1; j < width+1; ++j)
		{
			if(dp[0][j][1] == -1 && dp[0][j-1][1] == -1) break;
			dp[0][j][0] = 1;
		}

		//calculate number of paths from i-1,j and i,j-1
		//if not bad path
		for(int i = 1; i < width+1; ++i)
		{
			for(int j = 1; j < height+1; ++j)
			{	
				if(dp[i][j][1] != -1 || dp[i-1][j][1] != -1)
					dp[i][j][0] += dp[i-1][j][0];
				if(dp[i][j][1] != -1 || dp[i][j-1][1] != -1)
					dp[i][j][0] += dp[i][j-1][0];
			}
		}

		/*for(int i = 0; i < width+1; ++i)
		{
			for(int j = 0; j < height+1; ++j)
				cout << dp[i][j][0] << " ";
			cout << endl;
		}*/

		return dp[width][height][0];
	}

};

/*int main()
{
	int w, h;
	cin >> w >> h;

	AvoidRoads av;
	cout << av.numWays(w, h, {"0 0 1 0", "1 2 2 2", "1 1 2 1"}) << endl;
	
	return 0;
}*/