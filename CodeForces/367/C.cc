#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    vector<string> strs(n), rstrs(n);
    for (int i = 0; i < n; ++i) {
        cin >> strs[i];
        rstrs[i] = strs[i];
        reverse(rstrs[i].begin(), rstrs[i].end());
    }

    vector<vector<int64_t>> dp(n+1, vector<int64_t>(2));
    dp[0][0] = 0, dp[0][1] = c[0];
    //cout << dp[0][0] << " " << dp[0][1] << endl;
    for (int i = 1; i < n; ++i) {
        dp[i][0] = dp[i][1] = (int64_t)1 << 62;
        if (strs[i-1] <= strs[i]) dp[i][0] = min(dp[i][0], dp[i-1][0]);
        if (strs[i-1] <= rstrs[i]) dp[i][1] = min(dp[i][1], dp[i-1][0] + c[i]);
        if (rstrs[i-1] <= strs[i]) dp[i][0] = min(dp[i][0], dp[i-1][1]);
        if (rstrs[i-1] <= rstrs[i]) dp[i][1] = min(dp[i][1], dp[i-1][1] + c[i]);
        //cout << dp[i][0] << " " << dp[i][1] << endl;
    }

    cout << ((min(dp[n-1][0], dp[n-1][1]) == ((int64_t)1 << 62)) ? -1 : min(dp[n-1][0], dp[n-1][1])) << endl;

    return 0;
}