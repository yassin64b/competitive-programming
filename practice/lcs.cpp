#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	std::string s1, s2;
	cin >> s1 >> s2;

	int N = (int)s1.size(), M = (int)s2.size();
	vector<vector<int>> dp(N, vector<int>(M, 0));

	for(int i = 0; i < N; ++i)
	{
		for(int j = 0; j < M; ++j)
		{
			if(s1[i] == s2[j])
			{
				if(i > 0 && j > 0)
					dp[i][j] = dp[i-1][j-1] + 1;
				else
					dp[i][j] = 1;
			} 
			else
			{
				if(j == 0 && i == 0)
					dp[i][j] = 0;
				else if(j == 0)
					dp[i][j] = dp[i-1][j];
				else if(i == 0)
					dp[i][j] = dp[i][j-1];
				else
					dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	cout << dp[N-1][M-1] << endl;

	//reconstruct subsequence
	int i = N-1, j = M-1;
	string res;
	while(i >= 0 && j >= 0)
	{
		if(i && j && s1[i] == s2[j] && dp[i][j] == dp[i-1][j-1] + 1)
		{
			res.insert(0, 1, s1[i]);
			--i, --j;
		}
		else if (i && s1[i] != s2[j] && dp[i][j] == dp[i-1][j])
			--i;
		else if (j && s1[i] != s2[j] && dp[i][j] == dp[i][j-1])
			--j;
		else	if(dp[i][j] > 0)
		{
			res.insert(0,1,s1[i]);
			break;
		} 
	}


	cout << res << endl;

	return 0;
}