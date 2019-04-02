#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    const vector<int> primes{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
    const int m = primes.size();
    constexpr int MX = 58;
    vector<int> fact(MX + 1, 0);
    for (int i = 1; i <= MX; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i % primes[j] == 0) {
                fact[i] |= (1 << j);
            }
        }
    }
    constexpr int INF = 3'000;
    vector<vector<int>> dp(n + 1, vector<int>((1 << m), INF));
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int k = 1; k <= MX; ++k) {
            int x = (~fact[k] & ((1 << m) - 1));
            for (int j = x; ; j = (j - 1) & x) {
                if ((j & fact[k]) == 0) {
                    int new_j = (j | fact[k]);
                    dp[i + 1][new_j] = min(dp[i + 1][new_j], 
                                           dp[i][j] + abs(a[i] - k));
                }
                if (j == 0) break;
            }
        }
    }

    int j = min_element(begin(dp[n]), end(dp[n])) - begin(dp[n]);
    vector<int> b;

    for (int i = n - 1; i >= 0; --i) {
        for (int k = 1; k <= MX; ++k) {
            if ((j & fact[k]) == fact[k]) {
                int new_j = (j & ~fact[k]);
                if (dp[i][new_j] + abs(a[i] - k) == dp[i + 1][j]) {
                    b.push_back(k);
                    j = new_j;
                    break;
                }
            }
        }
    }

    reverse(begin(b), end(b));
    for (int x : b) {
        cout << x << " ";
    }
    cout << "\n";


    return 0;
}