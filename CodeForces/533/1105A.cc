#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int best_t = 1, res = 100 * 1000 + 1;
    for (int t = 1; t <= 100; ++t) {
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] < t) {
                cur += t - 1 - a[i];
            } else if (a[i] > t) {
                cur += a[i] - (t + 1);
            }
        }
        if (cur < res) {
            best_t = t;
            res = cur;
        }
    }
    cout << best_t << " " << res << "\n";


    return 0;
}