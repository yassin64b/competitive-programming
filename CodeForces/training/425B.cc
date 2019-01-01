#include <bits/stdc++.h>

using namespace std;

int calc_cost(const vector<vector<int>> &a, const vector<int> &r) {
    int total = 0, n = a.size(), m = a[0].size();
    for (int i = 0; i < n; ++i) {
        int cost1 = 0, cost2 = 0;
        for (int j = 0; j < m; ++j) {
            cost1 += (a[i][j] != r[j]);
            cost2 += (a[i][j] == r[j]);
        }
        total += min(cost1, cost2);
    }
    return total;
}

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    int res = n * m;
    if (n <= k) { // try every possibilty for one column
        for (int mask = 0; mask < (1 << n); ++mask) {
            vector<int> c(n);
            for (int shift = 0; shift < n; ++shift) {
                if (mask & (1 << shift)) {
                    c[shift] = 1;
                }
            }
            vector<vector<int>> b(m, vector<int>(n));
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    b[i][j] = a[j][i];
                }
            }
            res = min(res, calc_cost(b, c));
        }
    } else { // can't change every row --> try every fixed row
        for (int r = 0; r < n; ++r) {
            res = min(res, calc_cost(a, a[r]));
        }
    }
    
    cout << (res <= k ? res : -1) << "\n";

    return 0;
}