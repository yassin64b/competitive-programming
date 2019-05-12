#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<int> b(n), g(m);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    for (int j = 0; j < m; ++j) {
        cin >> g[j];
    }
    map<int, i64> cnt;
    i64 sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += (i64)b[i] * m;
        cnt[b[i]] += m - 1;
    }
    int mxb = *max_element(begin(b), end(b));
    for (int j = 0; j < m; ++j) {
        if (mxb > g[j]) {
            cout << -1 << "\n";
            return 0;
        } else if (mxb < g[j]) {
            if (cnt.empty()) {
                cout << -1 << "\n";
                return 0;
            }
            auto it = --cnt.end();
            auto &[k, v] = *it;
            sum += g[j] - k;
            --v;
            if (v == 0) {
                cnt.erase(it);
            }
        }
    }
    cout << sum << "\n";
    

    return 0;
}