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
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        bool happy = true;
        long long cur_sum = 0;
        for (int i = 0; i < n - 1; ++i) {
            cur_sum += a[i];
            if (cur_sum <= 0) {
                happy = false;
            }
        }
        cur_sum = 0;
        for (int i = n - 1; i > 0; --i) {
            cur_sum += a[i];
            if (cur_sum <= 0) {
                happy = false;
            }
        }
        cout << (happy ? "YES" : "NO") << "\n";
    }

    return 0;
}