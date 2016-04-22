#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;

	int *dp = new int[N+1];
	dp[1] = 0;

	for(int i = 2; i < N+1; ++i)
	{
		int res = dp[i-1];
		if(i%2 == 0)
			res = min(res, dp[i/2]);
		if(i%3 == 0)
			res = min(res, dp[i/3]);

		dp[i] = 1 + res; 
	}
	cout << dp[N] << endl;

	delete[] dp;

	return 0;
}