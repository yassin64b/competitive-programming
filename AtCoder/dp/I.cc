#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    vector<double> p(N);
    for (int i = 0; i < N; ++i) {
        cin >> p[i];
    }
    vector<double> dp(N + 1, 0.);
    dp[0] = 1.;
    for (int i = 0; i < N; ++i) {
        vector<double> nxt(N + 1, 0.);
        for (int num_head = 0; num_head <= i; ++num_head) {
            nxt[num_head + 1] += dp[num_head] * p[i];
            nxt[num_head] += dp[num_head] * (1 - p[i]);
        }
        dp = nxt;
    }
    cout.precision(17);
    cout << fixed << accumulate(begin(dp) + (N + 1) / 2, end(dp), 0.) << "\n";
    return 0;
}