#include <bits/stdc++.h>

using namespace std;

void cnt_leaves(int u, const vector<vector<int>> &g, vector<int> &cntl) {
    cntl[u] = (g[u].empty() == true);
    for (int v : g[u]) {
        cnt_leaves(v, g, cntl);
        cntl[u] += cntl[v];
    }
}

int solve(int u, const vector<vector<int>> &g, const vector<int> &op, 
          const vector<int> &cntl) {
    int res = 0;
    if (g[u].empty()) {
        return 1;
    }
    if (op[u]) {
        res = 1'000'000'000;
        for (int v : g[u]) {
            res = min(res, solve(v, g, op, cntl));
        }
    } else {
        for (int v : g[u]) {
            res += solve(v, g, op, cntl);
        }
    }
    return res;
}
int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> op(n);
    for (int i = 0; i < n; ++i) {
        cin >> op[i];
    }   
    vector<vector<int>> g(n);
    for (int i = 2; i <= n; ++i) {
        int f;
        cin >> f;
        g[f - 1].push_back(i - 1);
    }
    vector<int> cntl(n, 0);
    cnt_leaves(0, g, cntl);
    int k = cntl[0];
    cout << k - solve(0, g, op, cntl) + 1 << "\n";

    return 0;
}