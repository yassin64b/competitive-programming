#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    int res = 0;
    for (int i = 0; i < 10'000; ++i) {
        int cur = 0;
        for (int j = 0; j < n; ++j) {
            if (s[j] == '1') {
                if (i < b[j] || (i - b[j]) % (2 * a[j]) >= a[j]) {
                    ++cur;
                }
            } else {
                if (i >= b[j] && (i - b[j]) % (2 * a[j]) < a[j]) {
                    ++cur;
                }
            }
        }
        res = max(res, cur);
    }
    cout << res << "\n";

    return 0;
}