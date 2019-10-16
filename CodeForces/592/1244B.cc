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
        string s;
        cin >> s;
        int mx = n;
        int first = -1, last = -1;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                first = i;
                break;
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '1') {
                last = i;
                break;
            }
        }
        if (first != -1) {
            // start in 0
            int cur1 = last + 1 + last + 1;
            // start in n - 1
            int cur2 = n - first + n - first;
            mx = max(mx, max(cur1, cur2));
        }
        cout << mx << "\n";
    }
    return 0;
}