#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class ZigZag
{
public:
	int longestZigZag(vector<int> seq)
	{
		int N = (int) seq.size();
		
		vector<int> dp(2*N, 0); //2*i for neg next, 2*i+1 for pos
		
		dp[0] = dp[1] = 1;
		
		for(int i = 1; i < N; ++i)
		{
			for(int j = 0; j < i; ++j)
			{
				if(seq[j] < seq[i]) 
					dp[2*i] = max(dp[2*j+1]+1, dp[2*i]);
				else if(seq[j] > seq[i]) 
					dp[2*i+1] = max(dp[2*j]+1, dp[2*i+1]);
			}
		}
		
		return *max_element(dp.begin(), dp.end());
	}
};