#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n, h;
    cin >> n >> h;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int res = 0;
    for (int k = 1; k <= n; ++k) {
        vector<int> b(k);
        for (int i = 0; i < k; ++i) {
            b[i] = a[i];
        }
        sort(begin(b), end(b));
        reverse(begin(b), end(b));
        long long sum = 0;
        for (int i = 0; i < k; i += 2) {
            sum += b[i];
        }
        if (sum <= h) {
            res = k;
        }
    }
    cout << res << "\n";

    return 0;
}