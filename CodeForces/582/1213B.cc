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
        int mn = a.back(), cnt_bad = 0;
        for (int i = n - 2; i >= 0; --i) {
            cnt_bad += (a[i] > mn);
            mn = min(mn, a[i]);
        }
        cout << cnt_bad << "\n";
    }
    return 0;
}