#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    i64 n, k;
    cin >> n >> k;

    i64 low = 1, high = n, mx_even = 0;
    while (low <= high) {
        i64 mid = (low + high) / 2;
        i64 y = 2 * mid;
        i64 cnt = 0, range_sz = 2;
        while (y <= n) {
            i64 from = y;
            i64 to = min(y + range_sz - 1, n);
            cnt += to - from + 1;
            range_sz *= 2;
            y *= 2;
        }
        if (cnt >= k) {
            low = mid + 1;
            mx_even = 2 * mid;
        } else {
            high = mid - 1;
        }
    }
    low = 0, high = n;
    i64 mx_odd = 0;
    while (low <= high) {
        i64 mid = (low + high) / 2;
        i64 y = 2 * mid + 1;
        i64 cnt = 0, range_sz = 1;
        while (y <= n) {
            i64 from = y;
            i64 to = min(y + range_sz - 1, n);
            cnt += to - from + 1;
            range_sz *= 2;
            y *= 2;
        }
        if (cnt >= k) {
            low = mid + 1;
            mx_odd = 2 * mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << max(mx_even, mx_odd) << endl;

    return 0;
}