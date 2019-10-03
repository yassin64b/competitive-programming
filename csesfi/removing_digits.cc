#include <bits/stdc++.h>

using namespace std;

set<int> get_digs(int x) {
    set<int> digs;
    while (x) {
        digs.insert(x % 10);
        x /= 10;
    }
    return digs;
}
int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n;
    cin >> n;
    const int INF = n + 1;
    vector<int> dp(n + 1, INF);
    dp[n] = 0;
    for (int i = n; i > 0; --i) {
        set<int> digs = get_digs(i);
        for (int j : digs) {
            if (i - j >= 0) {
                dp[i - j] = min(dp[i - j], dp[i] + 1);
            }
        }
    }
    cout << dp[0] << "\n";
    
    return 0;
}