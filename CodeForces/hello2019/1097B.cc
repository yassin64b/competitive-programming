#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int mask = 0; mask < (1 << n); ++mask) {
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                cur = (cur + a[i]) % 360;
            } else {
                cur = (cur - a[i] + 360) % 360;
            }
        }
        if (cur == 0) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";

    return 0;
}