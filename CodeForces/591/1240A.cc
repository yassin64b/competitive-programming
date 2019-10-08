#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
        }
        int x, a;
        cin >> x >> a;
        int y, b;
        cin >> y >> b;
        long long k;
        cin >> k;

        sort(begin(p), end(p));
        reverse(begin(p), end(p));

        int low = 1, high = n, ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            vector<int> cont(mid, 0);
            for (int i = a - 1; i < mid; i += a) {
                cont[i] += x;
            }
            for (int i = b - 1; i < mid; i += b) {
                cont[i] += y;
            }
            sort(begin(cont), end(cont));
            reverse(begin(cont), end(cont));
            long long sum = 0;
            for (int i = 0; i < mid; ++i) {
                sum += 1LL * cont[i] * p[i] / 100;
            }
            if (sum >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}