#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> c(n), t(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }
    vector<int> d1, d2;
    for (int i = 1; i < n; ++i) {
        d1.push_back(c[i] - c[i - 1]);
        d2.push_back(t[i] - t[i - 1]);
    }
    sort(begin(d1), end(d1));
    sort(begin(d2), end(d2));

    if (c[0] == t[0] && c[n - 1] == t[n - 1] && d1 == d2) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}