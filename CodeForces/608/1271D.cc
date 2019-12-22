#include <bits/stdc++.h>

using namespace std;

struct castle {
    int a, b, c;
    vector<int> g;
};


int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    vector<castle> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i].a >> c[i].b >> c[i].c;
    }
    vector<int> mx_dom(n, -1);
    for (int i = 0; i < n; ++i)
        mx_dom[i] = i;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        c[u - 1].g.push_back(v - 1);
        mx_dom[v - 1] = max(mx_dom[v - 1], u - 1);
    }

    vector<int> cur(n + 1, 0);
    cur[0] = k;
    for (int i = 0; i < n; ++i) {
        if (cur[i] < c[i].a) {
            cout << -1 << "\n";
            return 0;
        }
        cur[i + 1] = cur[i] + c[i].b;
    }

    constexpr int MX = 5'000;
    constexpr int INF = MX * MX + 1;
    vector<vector<int>> dp(n + 1, vector<int>(MX + 1, -INF));
    dp[0][k] = 0;
    for (int i = 0; i < n; ++i) {
        vector<pair<int, int>> to_send;
        if (mx_dom[i] == i) {
            to_send.emplace_back(c[i].c, i);
        }
        for (int v : c[i].g) {
            if (i == mx_dom[v]) {
                to_send.emplace_back(c[v].c, v);
            }
        }
        sort(begin(to_send), end(to_send));
        reverse(begin(to_send), end(to_send));
        for (int j = c[i].a; j <= MX; ++j) {
            if (dp[i][j] < 0) continue;
            int add = 0;
            if (j + c[i].b <= MX)
                dp[i + 1][j + c[i].b] = max(dp[i + 1][j + c[i].b],
                                            dp[i][j]);
            for (int l = 0; l < (int)to_send.size(); ++l) {
                int nj = j + c[i].b - (l + 1);
                add += to_send[l].first;
                if (nj <= MX && nj >= 0) {
                    dp[i + 1][nj] = max(dp[i + 1][nj], dp[i][j] + add);
                } else {
                    break;
                }
            }
        }
    }
    cout << *max_element(begin(dp[n]), end(dp[n])) << "\n";




    return 0;
}