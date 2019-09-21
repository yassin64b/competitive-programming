#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int c, m, x;
        cin >> c >> m >> x;
        int mx_no = 0;
        int low = 0, high = min(c, m);
        while (low <= high) {
            int mid = (low + high) / 2;
            int tc = c - mid, tm = m - mid, tx = x;
            if (tc + tm + tx < mid) {
                high = mid - 1;
            } else {
                mx_no = mid;
                low = mid + 1;
            }
        }
        cout << mx_no << "\n";
    }

    return 0;
}