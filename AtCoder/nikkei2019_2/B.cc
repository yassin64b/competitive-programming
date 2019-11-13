#include <bits/stdc++.h>

using namespace std;
constexpr int MOD = 998'244'353;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> D(N), cnt(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> D[i];
        ++cnt[D[i]];
    }
    if (cnt[0] > 1 || D[0] != 0) {
        cout << 0 << "\n";
        return 0;
    }
    int res = 1;
    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < cnt[i]; ++j)
            res = (1LL * res * cnt[i - 1]) % MOD;
    }
    cout << res << "\n";


    return 0;
}