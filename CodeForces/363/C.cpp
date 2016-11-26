#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	vector<vector<int>> dp(n, vector<int>(3, 100000));
	if(!(a[0] == 0 || a[0] == 1)) dp[0][2] = 0;
	if(!(a[0] == 0 || a[0] == 2)) dp[0][1] = 0;
	dp[0][0] = 1;
	for(int i = 1; i < n; ++i)
	{
		dp[i][0] = *min_element(dp[i-1].begin(), dp[i-1].end())+1;
		if(a[i] == 2 || a[i] == 3) //gym open
		{
			dp[i][2] = min(dp[i-1][0], dp[i-1][1]);
		}
		if(a[i] == 1 || a[i] == 3) //contest
		{
			dp[i][1] = min(dp[i-1][0], dp[i-1][2]);
		}
	}
	cout << *min_element(dp[n-1].begin(), dp[n-1].end()) << endl;
	return 0;
}