#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n, z;
    cin >> n >> z;
    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    sort(begin(x), end(x));
    int low = 0, high = n / 2, ans = low;
    while (low <= high) {
        int mid = (low + high) / 2;
        vector<int> a, b;
        for (int i = 0; i < mid; ++i) {
            a.push_back(x[i]);
        }
        for (int i = n - 1; i > n - 1 - mid; --i) {
            b.push_back(x[i]);
        }
        reverse(begin(b), end(b));
        bool ok = true;
        for (int i = 0; i < mid; ++i) {
            if (b[i] - a[i] < z) {
                ok = false;
            }
        }
        if (ok) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << ans << "\n";
    return 0;
}