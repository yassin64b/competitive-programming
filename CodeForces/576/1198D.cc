#include <bits/stdc++.h>

using namespace std;

constexpr int MXN = 50;
int dp[MXN][MXN][MXN][MXN];

int recurse(int x1, int x2, int y1, int y2, int (&dp)[MXN][MXN][MXN][MXN],
             const vector<string> &g) {
    int& res = dp[x1][x2][y1][y2];
    if (res != -1) {
        return res;
    }
    if (x1 == x2 && y1 == y2 && g[x1][y1] == '.') {
        res = 0;
    } else {
        res = max(x2 - x1 + 1, y2 - y1 + 1);
    }
    for (int i = x1; i < x2; ++i) {
        res = min(res, recurse(x1, i, y1, y2, dp, g) 
                        + recurse(i + 1, x2, y1, y2, dp, g));
    }
    for (int i = y1; i < y2; ++i) {
        res = min(res, recurse(x1, x2, y1, i, dp, g)
                        + recurse(x1, x2, i + 1, y2, dp, g));
    }
    return res;
}

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> g(n);
    for (int i = 0; i < n; ++i) {
        cin >> g[i];
    }
    for (int x1 = 0; x1 < n; ++x1) {
        for (int x2 = 0; x2 < n; ++x2) {
            for (int y1 = 0; y1 < n; ++y1) {
                for (int y2 = 0; y2 < n; ++y2) {
                    dp[x1][x2][y1][y2] = -1;
                }
            }
        }
    }
    cout << recurse(0, n - 1, 0, n - 1, dp, g) << "\n";

    return 0;
}