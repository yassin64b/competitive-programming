#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n, p, k;
        cin >> n >> p >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(begin(a), end(a));
        int low = 0, high = n - 1, mx = low;
        while (low <= high) {
            int mid = (low + high) / 2;
            int cost = 0;
            for (int i = mid; i >= 0; i -= k) {
                cost += a[i];
            }
            if (cost > p) {
                high = mid - 1;
            } else {
                low = mid + 1;
                mx = mid + 1;
            }
        }
        low = 0, high = k - 1;
        int mx2 = low, num_k = mx / k;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (mid + num_k * k >= n) {
                high = mid - 1;
                continue;
            }
            int cost = 0;
            for (int i = mid + num_k * k; i >= 0; ) {
                cost += a[i];
                if (i >= k - 1) {
                    i -= k;
                } else {
                    --i;
                }
            }
            if (cost > p) {
                high = mid - 1;
            } else {
                low = mid + 1;
                mx2 = mid + 1;
            }
        }
        cout << num_k * k + mx2 << "\n";
    }
    return 0;
}