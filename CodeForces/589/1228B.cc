#include <bits/stdc++.h>

using namespace std;
constexpr int MOD = 1'000'000'007;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int h, w;
    cin >> h >> w;
    vector<int> r(h), c(w);
    for (int i = 0; i < h; ++i) cin >> r[i];
    for (int j = 0; j < w; ++j) cin >> c[j];
    vector<vector<int>> g(h, vector<int>(w, -1));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < r[i]; ++j) {
            g[i][j] = 1;
        }
        if (r[i] < w) {
            g[i][r[i]] = 0;
        }
    }
    int res = 1;
    for (int j = 0; j < w; ++j) {
        for (int i = 0; i < c[j]; ++i) {
            if (g[i][j] == 0) {
                res = 0;
            } else {
                g[i][j] = 1;
            }
        }
        if (c[j] < h) {
            if (g[c[j]][j] == 1) {
                res = 0;
            } else {
                g[c[j]][j] = 0;
            }
        }
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (g[i][j] == -1) {
                res = (2 * res) % MOD;
            }
        }
    }
    cout << res << "\n";

    return 0;
}