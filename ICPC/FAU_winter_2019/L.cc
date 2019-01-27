#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> s;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        s.insert(a[i]);
    }
    int mn = *min_element(begin(a), end(a));
    int mx = *max_element(begin(a), end(a));
    for (int i = 0; i < n; ++i) {
        if (mn < a[i] + 1 && a[i] + 1 < mx && !s.count(a[i] + 1)) {
            cout << a[i] + 1 << "\n";
            return 0;
        } else if (mn < a[i] - 1 && a[i] - 1 < mx && !s.count(a[i] - 1)) {
            cout << a[i] - 1 << "\n";
            return 0;
        }
    }
    cout << "impossible" << "\n";
    return 0;
}