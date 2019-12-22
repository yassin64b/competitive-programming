#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int a[2], b[2], c[2], d[7];
        for (int j = 0; j < 2; ++j) 
            cin >> a[j] >> b[j] >> c[j];
        for (int j = 0; j < 7; ++j)
            cin >> d[j];
        bool found = false;
        int f[7];
        for (f[1] = 0; !found && f[1] <= min(a[0], b[0]) && f[1] <= d[1]; ++f[1]) {
            a[0] -= f[1];
            b[0] -= f[1];
            for (f[2] = 0; !found && f[2] <= min(a[0], c[0]) && f[2] <= d[2]; ++f[2]) {
                a[0] -= f[2];
                c[0] -= f[2];
                for (f[4] = 0; !found && f[4] <= min(b[0], c[0]) && f[4] <= d[4]; ++f[4]) {
                    b[0] -= f[4];
                    c[0] -= f[4];
                    f[0] = min(d[0], min(a[0], min(b[0], c[0])));
                    f[3] = min(d[3], a[0] - f[0]);
                    f[5] = min(d[5], b[0] - f[0]);
                    f[6] = min(d[6], c[0] - f[0]);
                    for (int j = 0; j < 7; ++j)
                        d[j] -= f[j];
                    if (d[0] + d[1] + d[2] + d[3] <= a[1]
                        && d[0] + d[1] + d[4] + d[5] <= b[1]
                        && d[0] + d[2] + d[4] + d[6] <= c[1]) {
                        found = true;
                        for (int j = 0; j < 7; ++j) {
                            cout << f[j] << " ";
                        }
                        cout << "\n";
                    }

                    for (int j = 0; j < 7; ++j)
                        d[j] += f[j];
                    b[0] += f[4];
                    c[0] += f[4];
                }
                a[0] += f[2];
                c[0] += f[2];
            }
            a[0] += f[1];
            b[0] += f[1];
        }
        if (!found) {
            cout << -1 << "\n";
        }
    }
    return 0;
}