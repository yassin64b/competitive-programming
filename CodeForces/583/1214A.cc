#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n, d, e;
    cin >> n >> d >> e;
    int mn = n;
    for (int cnt_5 = 0; cnt_5 * 5LL * e <= n; ++cnt_5) {
        int left_r = n - cnt_5 * 5LL * e;
        int num_d = left_r / d;
        left_r -= num_d * d;
        mn = min(mn, left_r);
    }
    cout << mn << "\n";

    return 0;
}