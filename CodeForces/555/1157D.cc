#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;

    i64 sub = (i64)k * (k + 1) / 2;
    if (sub > n) {
        cout << "NO\n";
        return 0;
    }
    n -= sub;
    vector<int> a(k, n / k);
    for (int i = k - 1, cnt = n % k; i >= 0 && cnt > 0; --i, --cnt) {
        ++a[i];
    }
    for (int i = 0; i < k; ++i) {
        a[i] += i + 1;
    }
    if (k >= 2 && a[1] > 2 * a[0]) {
        --a[1];
        ++a[k - 1];
        if (a[0] == a[1] || a[k - 1] > 2 * a[k - 2]) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    for (int x : a) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}