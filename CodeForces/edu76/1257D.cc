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
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int m;
        cin >> m;
        vector<int> mxp(n + 1);
        for (int i = 0; i < m; ++i) {
            int p, s;
            cin >> p >> s;
            mxp[s] = max(mxp[s], p);
        }
        for (int i = n - 1; i >= 1; --i) {
            mxp[i] = max(mxp[i], mxp[i + 1]);
        }
        int days = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] > mxp[1]) {
                cout << "-1\n";
                goto nxt_case;
            }
        }
        for (int i = 0; i < n; ++i) {
            ++days;
            int hero = 1;
            int mx = a[i];
            while (i + 1 < n && hero < n 
                   && mxp[hero + 1] >= max(mx, a[i + 1])) {
                mx = max(mx, a[i + 1]);
                ++hero;
                ++i;
            }
        }
        cout << days << "\n";

        nxt_case:;
    }
    return 0;
}