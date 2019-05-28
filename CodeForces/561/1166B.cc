#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    const string vows = "aeiou";

    int k;
    cin >> k;
    for (int n = 5; n < k; ++n) {
        if (k % n == 0) {
            int m = k / n;
            if (m >= 5) {
                string s;
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < m; ++j) {
                        s += vows[(i + j) % 5];
                    }
                }
                cout << s << "\n";
                return 0;
            }
        }
    }
    cout << -1 << "\n";

    return 0;
}