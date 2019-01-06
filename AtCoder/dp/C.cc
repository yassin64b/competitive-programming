#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    vector<vector<int>> act(N, vector<int>(3));
    for (int i = 0; i < N; ++i) {
        cin >> act[i][0] >> act[i][1] >> act[i][2];
    }
    vector<vector<int>> dp(N + 1, vector<int>(3, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                if (k != j) {
                    dp[i + 1][k] = max(dp[i + 1][k], dp[i][j] + act[i][k]);
                }
            }
        }
    }
    cout << *max_element(begin(dp[N]), end(dp[N])) << "\n";
    return 0;
}