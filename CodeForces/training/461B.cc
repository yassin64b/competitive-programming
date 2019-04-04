#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 1'000'000'007;

int mod_inv(int a) {
    int b = MOD - 2, c = MOD;
    long long x = 1, y = a;
    while (b > 0) {
        if (b % 2 == 1) {
            x = (x * y) % c;
        }
        y = (y * y) % c;
        b /= 2;
    }
    return x % c;
}

void dfs(int u, const vector<vector<int>> &g, const vector<int> &x,
         vector<int> &dp1, vector<int> &dp2) {
    for (int v : g[u]) {
        dfs(v, g, x, dp1, dp2);
    }

    if (x[u] == 1) { // combine with other white components
        dp1[u] = 1;
        for (int v : g[u]) {
            dp1[u] = (1LL * dp1[u] * dp2[v]) % MOD;
        }
    } else { // combine with exactly 1 black component, rest white
        int tmp = 1;
        for (int v : g[u]) {
            tmp = (1LL * tmp * dp2[v]) % MOD;
        }
        for (int v : g[u]) {
            int cur = 1LL * tmp * mod_inv(dp2[v]) % MOD;
            cur = 1LL * cur * dp1[v] % MOD;
            dp1[u] = (dp1[u] + cur) % MOD;
        }
    }

    if (x[u] == 0) { // combine with other white components
        dp2[u] = 1;
        for (int v : g[u]) {
            dp2[u] = (1LL * dp2[u] * dp2[v]) % MOD;
        }
    }
    // cut of the edge to the parent
    dp2[u] = (dp2[u] + dp1[u]) % MOD;
}

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int p;
        cin >> p;
        g[p].push_back(i + 1);
    }
    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    // dp1[u] = no. ways to reach the parent of u, s.t.
    // the open component has exactly 1 black node
    // dp2[u] = no. ways to reach the parent of u, s.t.
    // the open component has only white nodes
    vector<int> dp1(n), dp2(n);
    dfs(0, g, x, dp1, dp2);
    cout << dp1[0] << "\n";

    return 0;
}