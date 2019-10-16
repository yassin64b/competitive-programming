#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    i64 n, p;
    int d, w;
    // w points for win, d points for draw
    cin >> n >> p >> w >> d;
    for (i64 x = 0; x <= max(d, w); ++x) {
        i64 restp = p - x * w;
        if (restp % d == 0 && restp >= 0) {
            i64 y = restp / d;
            if (x + y <= n) {
                cout << x << " " << y << " " << n - (x + y) << "\n";
                return 0;
            }
        }
    }
    for (i64 y = 0; y <= max(d, w); ++y) {
        i64 restp = p - y * d;
        if (restp % w == 0 && restp >= 0) {
            i64 x = restp / w;
            if (x + y <= n) {
                cout << x << " " << y << " " << n - (x + y) << "\n";
                return 0;
            }
        }
    }
    cout << -1 << "\n";

    return 0;
}