#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    ifstream fin("teamwork.in");
    ofstream fout("teamwork.out");

    int N, K;
    fin >> N >> K;
    vector<int> skill(N);
    for (int i = 0; i < N; ++i) {
        fin >> skill[i];
    }
    vector<int> dp(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        int mx = 0;
        for (int j = 1; j <= K && i + j <= N; ++j) {
            mx = max(mx, skill[i + j - 1]);
            dp[i + j] = max(dp[i + j], dp[i] + j * mx);
        }
    }
    fout << dp[N] << "\n";

    return 0;
}