#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

inline i64 mn_last(int k, i64 cur, i64 sum) {
    if (k == 0) return cur;
    return (1LL << (k - 1)) * (cur + sum + 1);
    /*for (int i = 0; i < k; ++i) {
        sum += cur;
        cur = sum + 1;
        if (sum > 2e14) {
            return 2e14;
        }
    }
    return cur;*/
}

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int Q;
    cin >> Q;
    for (int q = 0; q < Q; ++q) {
        i64 a, b, m;
        cin >> a >> b >> m;
        bool done = false;
        for (int k = 1; !done && k <= 50; ++k) {
            i64 sum = a;
            vector<i64> v(k);
            v[0] = a;
            for (int i = 1; i < k; ++i) {
                i64 low = sum + 1, high = sum + m, ans = low;
                while (low <= high) {
                    i64 mid = (low + high) / 2;
                    i64 mn_b = mn_last(k - i - 1, mid, sum);
                    if (mn_b <= b) {
                        ans = mid;
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
                if (ans > b) {
                    break;
                }
                sum += ans;
                v[i] = ans;
            }
            if (v.back() == b) {
                done = true;
                cout << k << " ";
                for (i64 x : v) {
                    cout << x << " ";
                }
                cout << "\n";
            }
        }
        if (!done) {
            cout << -1 << "\n";
        }
    }
    return 0;
}