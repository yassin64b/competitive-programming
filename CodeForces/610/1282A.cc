#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int a, b, c, r;
        cin >> a >> b >> c >> r;
        int beg_c = c - r;
        int end_c = c + r;
        if (a > b) swap(a, b);
        int part_cov = max(0, min(b, end_c) - max(a, beg_c));
        cout << b - a - part_cov << "\n";
    }
    return 0;
}