#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

int main() 
{
	int N;
	cin >> N;

	vector<int> a(N);
	vector<int> dp(N);
	for(int i = 0; i < N; ++i)
	{
		cin >> a[i];
		--a[i];
		dp[i] = i;
	}

	for(int i = 0; i < N; ++i)
	{
		if(dp[i] + 1 < dp[a[i]])
			dp[a[i]] = dp[i] + 1;

		int j = i;
		while(j > 0 && j < N && dp[j-1] + 1 < dp[j])
		{
			dp[j] = dp[j-1] + 1;
			if(dp[j] + 1 < dp[a[j]])
				dp[a[j]] = dp[j] + 1;
			++j;
		}
		j = i;
		while(j > 0 && j < N && dp[j] + 1 < dp[j-1])
		{
			dp[j-1] = dp[j] + 1;
			if(dp[j-1] + 1 < dp[a[j-1]])
				dp[a[j-1]] = dp[j-1] + 1;
			--j;
		}
		if(dp[i] + 1 < dp[a[i]])
			dp[a[i]] = dp[i] + 1;	
		
	}

	for(int i = 0; i < N; ++i)
		cout << dp[i] << ' ';

	return 0;
}