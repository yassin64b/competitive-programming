#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> a(n + 1);
    a[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    long long res = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] < a[i - 1]) {
            int left = a[i];
            int right = a[i - 1] - a[i];
            res += 1LL * left * right;
        } else if (a[i] > a[i - 1]) {
            int left = a[i] - a[i - 1];
            int right = n - a[i] + 1;
            res += 1LL * left * right;
        }
    }

    cout << res << "\n";

    return 0;
}