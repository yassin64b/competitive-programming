#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
constexpr i64 INF = 1'000'000'000'000'000;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> c(3, vector<int>(n));
    for (int j = 0; j < 3; ++j) {
        for (int i = 0; i < n; ++i) {
            cin >> c[j][i];
        }
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }
    for (int u = 0; u < n; ++u) {
        if (g[u].size() > 2U) {
            cout << -1 << "\n";
            return 0;
        }
    }
    int u1 = -1;
    for (int u = 0; u < n; ++u) {
        if (g[u].size() == 1U) {
            u1 = u;
            break;
        }
    }
    int u2 = g[u1][0];
    i64 mn = INF;
    vector<int> res_col;
    for (int i1 = 0; i1 < 3; ++i1) {
        for (int i2 = 0; i2 < 3; ++i2) {
            if (i1 == i2) continue;
            int uc = u2, ul = u1;
            vector<int> col(n, 0);
            col[uc] = i2;
            col[ul] = i1;
            while (g[uc].size() == 2U) {
                int un = g[uc][0];
                if (un == ul) un = g[uc][1];
                int cn = 0;
                if (col[uc] == cn || col[ul] == cn) ++cn;
                if (col[uc] == cn || col[ul] == cn) ++cn;
                col[un] = cn;
                ul = uc;
                uc = un;
            }
            i64 cost = 0;
            for (int u = 0; u < n; ++u) {
                cost += c[col[u]][u];
            }
            if (cost < mn) {
                res_col = col;
                mn = cost;
            }
        }
    }
    cout << mn << "\n";
    for (int i = 0; i < n; ++i) {
        cout << res_col[i] + 1 << " ";
    }
    cout << "\n";

    return 0;
}