#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n;
        cin >> n;
        vector<int> d(n);
        for (int i = 0; i < n; ++i) {
            cin >> d[i];
        }
        sort(begin(d), end(d));
        i64 x = (i64)d[0] * d.back();
        int cnt = 0;
        for (int i = 2; (i64)i * i <= x; ++i) {
            if (x % i == 0) {
                ++cnt;
                if (i != x / i) {
                    ++cnt;
                }
            }
        }
        bool ok = true;
        for (int y : d) {
            if (x % y) {
                ok = false;
            }
        }
        cout << (ok && cnt == n ? x : -1) << "\n";
    }
    
    return 0;
}