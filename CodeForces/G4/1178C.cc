#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    constexpr int MOD = 998244353;

    int w, h;
    cin >> w >> h;
    int res = 1;
    for (int i = 0; i < (w + h); ++i) {
        res = 2 * res % MOD;
    }
    cout << res << "\n";

    return 0;
}