#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int Q;
    cin >> Q;
    constexpr int BSZ = 700, SZ = 500'000;
    vector<int> a(SZ + 1, 0);
    vector<vector<int>> asum(BSZ, vector<int>(BSZ, 0));
    for (int q = 0; q < Q; ++q) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1) {
            a[x] += y;
            for (int px = 1; px < BSZ; ++px) {
                int py = x % px;
                asum[px][py] += y;
            }
        } else {
            assert(t == 2);
            int res = 0;
            if (x < BSZ) {
                res = asum[x][y];
            } else {
                for (int i = y; i <= SZ; i += x) {
                    res += a[i];
                }
            }
            cout << res << "\n";
        }
    }
    return 0;
}