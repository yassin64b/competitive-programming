#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
        
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    i64 res = 0, left = 0;
    for (int i = 0; i < n; ++i) {
        i64 mx = min(left, a[i] / 2LL);
        res += mx;
        left -= mx;
        a[i] -= 2 * mx;
        res += a[i] / 3;
        a[i] %= 3;
        left += a[i];
    }
    cout << res << "\n";

    return 0;
}