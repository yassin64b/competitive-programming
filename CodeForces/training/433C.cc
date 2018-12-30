#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

i64 val(int a, const vector<int> &v) {
    i64 res = 0;
    for (int x : v) {
        res += abs(x - a);
    }
    return res;
}

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < m; ++i) {
        if (a[i - 1] != a[i]) {
            adj[a[i]].push_back(a[i - 1]);
        }
    }
    for (int i = 0; i + 1 < m; ++i) {
        if (a[i + 1] != a[i]) {
            adj[a[i]].push_back(a[i + 1]);
        }
    }
    i64 old_res = 0;
    for (int i = 1; i < m; ++i) {
        old_res += abs(a[i] - a[i - 1]);
    }
    i64 best_res = old_res;
    constexpr i64 INF = 1'000'000'000'000;
    for (int i = 1; i <= n; ++i) {
        if (adj[i].empty()) {
            continue;
        }
        /*int low = 1, high = n; // ternary search also works
        i64 best = INF;
        while (low <= high) {
            int mid = (low + high) / 2;
            i64 cur1 = val(mid, adj[i]);
            i64 cur2 = val(mid + 1, adj[i]);
            best = min(best, min(cur1, cur2));
            if (cur1 <= cur2) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }*/
        // take median
        sort(begin(adj[i]), end(adj[i]));
        int len = adj[i].size();
        int med = adj[i][len / 2];
        if (len % 2 == 0) {
            med = (med + adj[i][len / 2 - 1]) / 2;
        }
        i64 best = val(med, adj[i]);

        i64 old_val = val(i, adj[i]);
        assert(best <= old_val);
        best_res = min(best_res, old_res - old_val + best);
    }
    cout << best_res << "\n";

    return 0;
}