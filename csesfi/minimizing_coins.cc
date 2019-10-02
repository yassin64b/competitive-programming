#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    sort(begin(c), end(c));
    const int INF = x + 1;
    vector<int> dp(x + 1, INF);
    dp[0] = 0;
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i + c[j] <= x) {
                dp[i + c[j]] = min(dp[i + c[j]], dp[i] + 1);
            } else {
                break;
            }
        }
    }
    cout << (dp[x] == INF ? -1 : dp[x]) << "\n";

    return 0;
}