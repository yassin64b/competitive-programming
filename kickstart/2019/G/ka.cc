#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int N, M, Q;
        cin >> N >> M >> Q;
        vector<int> P(M), R(Q);
        vector<int> torn(N + 1, 0);
        for (int i = 0; i < M; ++i) {
            cin >> P[i];
            torn[P[i]] = 1;
        } 
        for (int i = 0; i < Q; ++i) 
            cin >> R[i];
        vector<int> cnt(N + 1, 0);
        for (int i = 1; i <= N; ++i) {
            for (int j = i; j <= N; j += i) {
                cnt[i] += !torn[j];
            }
        }
        long long res = 0;
        for (int r : R) 
            res += cnt[r];
        cout << "Case #" << t << ": " << res << "\n";
    }
    return 0;
}