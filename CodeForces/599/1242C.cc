#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int k;
    cin >> k;
    vector<vector<int>> a(k);
    map<int, pair<int, int>> inv;
    vector<i64> sums(k);
    for (int i = 0; i < k; ++i) {
        int n;
        cin >> n;
        a[i].resize(n);
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            inv[a[i][j]] = {i, j};
            sums[i] += a[i][j];
        }
    }
    if (accumulate(begin(sums), end(sums), 0LL) % k) {
        cout << "No\n";
        return 0;
    }
    const long long need = accumulate(begin(sums), end(sums), 0LL) / k;
    vector<int> cycles((1 << k), 0);
    vector<vector<pair<int, int>>> recon((1 << k));
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < (int)a[i].size(); ++j) {
            int cur = 0; //set<int> cur;
            int x = i, y = j;
            vector<pair<int, int>> v;
            while (true) {
                v.emplace_back(x, y);
                cur |= (1 << x); //cur.insert(x);
                long long cur_need = need - (sums[x] - a[x][y]);
                if (abs(cur_need) > 1e9 || !inv.count(cur_need)) {
                    cur = 0; //cur.clear();
                    break;
                }
                auto [nx, ny] = inv[cur_need];
                if (cur & (1 << nx)) { //cur.count(nx)) {
                    if (nx != i || ny != j) 
                        cur = 0; //cur.clear();
                    break;
                }
                x = nx;
                y = ny;
            }
            if (cur) { //!cur.empty()) {
                cycles[cur] = 1; //cycles.push_back(cur);
                recon[cur] = v;
            }
        }
    }
    vector<int> dp((1 << k), 0);
    dp[0] = 1;
    for (int m1 = 0; m1 < (1 << k); ++m1) {
        for (int m2 = m1; m2; m2 = (m2 - 1) & m1) {
            if (cycles[m2] && dp[m1 & ~m2]) {
                dp[m1] = 1;
            }
        }
    }
    if (dp[(1 << k) - 1]) {
        cout << "Yes\n";
        vector<int> c(k), p(k);
        int m1 = (1 << k) - 1;
        while (m1) {
            for (int m2 = m1; m2; m2 = (m2 - 1) & m1) {
                if (cycles[m2] && dp[m1 & ~m2]) {
                    auto [x, y] = recon[m2][0];
                    c[x] = y;
                    p[x] = recon[m2].back().first;
                    for (int i = 1; i < (int)recon[m2].size(); ++i) {
                        auto [nx, ny] = recon[m2][i];
                        c[nx] = ny;
                        p[nx] = x;
                        x = nx;
                        y = ny;
                    }
                    m1 = (m1 & ~m2);
                    break;
                }
            }
        }
        for (int i = 0; i < k; ++i) {
            cout << a[i][c[i]] << " " << p[i] + 1 << "\n";
        }
    } else {
        cout << "No\n";
    }

    return 0;
}