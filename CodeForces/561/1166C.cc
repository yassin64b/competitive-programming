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
        if (a[i] < 0) {
            a[i] = -a[i];
        }
    }
    sort(begin(a), end(a));
    long long res = 0;
    for (int l = 0, r = 0; l < n; ++l) {
        r = max(r, l);
        while (r < n && a[r] <= 2 * a[l]) {
            ++r;
        }
        res += r - l - 1;
    }
    cout << res << "\n";


    return 0;
}