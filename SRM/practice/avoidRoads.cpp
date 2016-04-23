#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <utility>
#include <sstream>
#include <map>
using namespace std;

typedef long long lli;
typedef pair<int,int> pii;

class AvoidRoads
{
public:
	lli numWays(int width, int height, vector<string> bad)
	{
		lli dp[101][101] = {0}; 
		map<pii, set<pii>> m;

		int a, b, c, d;
		for(string& s: bad)
		{
			stringstream ss(s);
			ss >> a >> b >> c >> d;

			if(a < c || b < d)
				m[make_pair(a,b)].insert(make_pair(c,d));
			else
				m[make_pair(c,d)].insert(make_pair(a,b));
		}

		dp[0][0] = 1;
		for(int i = 1; i < width+1; ++i)
		{
			if(m[make_pair(i-1,0)].find(make_pair(i,0)) != m[make_pair(i-1,0)].end()) break;
			dp[i][0] = 1;
		}
		for(int j = 1; j < height+1; ++j)
		{
			if(m[make_pair(0,j-1)].find(make_pair(0,j)) != m[make_pair(0,j-1)].end()) break;
			dp[0][j] = 1;
		}

		for(int i = 1; i < width+1; ++i)
		{
			for(int j = 1; j < height+1; ++j)
			{	
				if(m[make_pair(i-1,j)].find(make_pair(i,j)) == m[make_pair(i-1,j)].end())
					dp[i][j] += dp[i-1][j];
				if(m[make_pair(i,j-1)].find(make_pair(i,j)) == m[make_pair(i,j-1)].end())
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
	cout << av.numWays(w, h, {"1 2 2 2", "1 1 2 1"}) << endl;
	
	return 0;
}*/