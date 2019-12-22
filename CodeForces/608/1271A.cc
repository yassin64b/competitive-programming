#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    // e : a, d
    // f : b, c, d
    int mx_cost = 0;
    if (f > e) {
        int cnt = min(b, min(c, d));
        mx_cost += cnt * f;
        d -= cnt;
        cnt = min(a, d);
        mx_cost += cnt * e;
    } else {
        int cnt = min(a, d);
        mx_cost += cnt * e;
        d -= cnt;
        cnt = min(b, min(c, d));
        mx_cost += cnt * f;
    }
    cout << mx_cost << "\n";

    return 0;
}