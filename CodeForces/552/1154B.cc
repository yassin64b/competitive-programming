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
    if (n == 1) {
        cout << 0 << "\n";
        return 0;
    }
    sort(begin(a), end(a));
    vector<int> v{a[0], a[n - 1], (a[0] + a[n - 1]) / 2};
    set<int> res;
    for (int x : v) {
        set<int> d;
        for (int y : a) {
            if (x != y) {
                d.insert(abs(x - y));
            }
        }
        if (d.size() <= 1U) {
            res.insert(d.empty() ? 0 : *d.begin());
        }
    }
    cout << (res.empty() ? -1 : *res.begin()) << "\n";

    return 0;
}