#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void dfs(int u, const vector<vector<int>> &g, vector<int> &vis,
         const vector<int> &B, 
         vector<i64> &dp1, vector<i64> &dp2, vector<i64> &dp3) {
    vis[u] = 1;
    vector<int> chil;
    for (int v : g[u]) {
        if (!vis[v]) {
            dfs(v, g, vis, B, dp1, dp2, dp3);
            chil.push_back(v);
        }
    }
    if (chil.empty()) {
        dp1[u] = B[u];
        dp3[u] = 0;
    } else { 
        // place light
        dp1[u] = B[u];
        for (int v : chil) {
            // either v is light also
            // or v is illum already
            // or v was dark -> add B[v]
            dp1[u] += max(dp1[v], max(dp2[v], dp3[v] + B[v]));
        }

        // dont place light but be illum from 1+ child
        i64 sum12 = 0;
        for (int v : chil) {
            sum12 += max(dp1[v], max(dp2[v], dp3[v]));
        }
        for (int v : chil) {
            // fix v to be light
            i64 vmx = max(dp1[v], max(dp2[v], dp3[v]));
            dp2[u] = max(dp2[u], B[u] + sum12 - vmx + dp1[v]);
        }

        // dont place light, dont be illum
        dp3[u] = 0;
        for (int v : chil) {
            dp3[u] += max(dp2[v], dp3[v]);
        }
    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int V;
        cin >> V;
        vector<int> B(V);
        for (int i = 0; i < V; ++i) {
            cin >> B[i];
        }
        vector<vector<int>> g(V);
        for (int i = 0; i < V - 1; ++i) {
            int X, Y;
            cin >> X >> Y;
            g[X - 1].push_back(Y - 1);
            g[Y - 1].push_back(X - 1);
        }
        constexpr i64 INF = 100'000'000'000;
        vector<int> vis(V, 0);
        vector<i64> dp1(V, -INF), dp2(V, -INF), dp3(V, -INF);
        dfs(0, g, vis, B, dp1, dp2, dp3);
        cout << "Case #" << t << ": " << max(dp1[0], max(dp2[0], dp3[0])) << "\n";
    }
    return 0;
}