#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    string s, t;
    cin >> s >> t;
    const int n = s.size(), m = t.size();
    vector<vector<int>> nxt_occ(n + 1, vector<int>(26, n));
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < 26; ++j) {
            if (s[i] == j + 'a') {
                nxt_occ[i][j] = i;
            } else {
                nxt_occ[i][j] = nxt_occ[i + 1][j];
            }
        }
    }
    long long res = 0;
    for (int i = 0, j = 0; i < m; ++i) {
        int k = t[i] - 'a';
        if (nxt_occ[j][k] < n) {
            res += nxt_occ[j][k] - j + 1;
            j = nxt_occ[j][k] + 1;     
        } else {
            res += n - j - 1;
            ++res;
            j = 0;
            if (nxt_occ[j][k] < n) {
                res += nxt_occ[j][k] - j + 1;
                j = nxt_occ[j][k] + 1;
            } else {
                cout << -1 << "\n";
                return 0;
            }
        }
        if (j >= n) {
            j = 0;
        }
    }
    cout << res << "\n";

    return 0;
}