#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<int> a(M), b(M);
    vector<vector<int>> c(M);
    for (int i = 0; i < M; ++i) {
        cin >> a[i] >> b[i];
        c[i].resize(b[i]);
        for (int j = 0; j < b[i]; ++j) {
            cin >> c[i][j];
            --c[i][j];
        }
    }
    constexpr int INF = 1'000'000'000;
    const int MX = 1 << N;
    vector<int> dp(MX, INF);
    dp[0] = 0;
    for (int i = 0; i < M; ++i) {
        vector<int> nxt(dp);
        for (int mask = 0; mask < MX; ++mask) {
            int nmask = mask;
            for (int j = 0; j < b[i]; ++j) {
                nmask |= (1 << c[i][j]);
            }
            nxt[nmask] = min(nxt[nmask], dp[mask] + a[i]);
        }
        dp = nxt;
    }
    cout << (dp[MX - 1] == INF ? -1 : dp[MX - 1]) << "\n";

    return 0;
}