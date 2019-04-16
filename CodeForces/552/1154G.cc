#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> a(n);
    constexpr int MX = 10'000'000;
    vector<vector<int>> b(MX + 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[a[i]].push_back(i + 1);
    }
    i64 res = 1e18;
    int ri = -1, rj = -1;
    for (int g = 1; g <= MX && g < res; ++g) {
        if (b[g].size() >= 2U) {
            res = g;
            ri = b[g][0];
            rj = b[g][1];
            continue;
        }
        vector<pair<int, int>> cand;
        for (int i = g; i <= MX && i < res && cand.size() < 2U; i += g) {
            for (int j : b[i]) {
                if (cand.size() >= 2U) break;
                cand.emplace_back(j, i);
            }
        }
        if (cand.size() >= 2U) {
            i64 cur = (i64)cand[0].second * cand[1].second / g;
            if (cur < res) {
                res = cur;
                ri = cand[0].first;
                rj = cand[1].first;
            }
        }
    }
    if (ri > rj) {
        swap(ri, rj);
    }
    cout << ri << " " << rj << endl;

    return 0;
}