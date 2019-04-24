#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

i64 gcd(i64 a, i64 b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<i64> x(n), p(m);
    vector<i64> y;
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
        if (i > 0) y.push_back(x[i] - x[i - 1]);
    }
    for (int j = 0; j < m; ++j) {
        cin >> p[j];
    }

    i64 d = y[0];
    for (int i = 1; i < (int)y.size(); ++i) {
        d = gcd(d, y[i]);
    }
    for (int j = 0; j < m; ++j) {
        if (d % p[j] == 0) {
            cout << "YES\n";
            cout << x[0] << " " << j + 1 << "\n";
            return 0;
        }
    }
    cout << "NO\n";

    return 0;
}