#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<vector<int>> occ(n + 1);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            occ[a[i]].push_back(i);
        }
        int res = n + 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j < (int)occ[i].size(); ++j) {
                res = min(res, occ[i][j] - occ[i][j - 1] + 1);
            }
        }
        cout << (res > n ? -1 : res) << "\n";
    }
    return 0;
}