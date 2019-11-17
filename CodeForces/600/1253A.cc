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
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) 
            cin >> a[i];
        for (int i = 0; i < n; ++i)
            cin >> b[i];
        int first_d = n, last_d = -1;
        for (int i = 0; i < n; ++i) {
            if (a[i] != b[i]) {
                first_d = i;
                break;
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            if (a[i] != b[i]) {
                last_d = i;
                break;
            }
        }
        bool ok = true;
        for (int i = first_d; i <= last_d; ++i) {
            if (a[i] - b[i] != a[first_d] - b[first_d] || a[i] - b[i] > 0) {
                ok = false;
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
    
    return 0;
}