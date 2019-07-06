#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    for (int i = 1; i < n; ++i) {
        s[i] += s[i - 1];
    }
    int q;
    cin >> q;
    for (int i = 0, l, r; i < q; ++i) {
        cin >> l >> r;
        cout << (s[r - 1] - (l - 2 >= 0 ? s[l - 2] : 0)) / 10 << "\n";
    }

    return 0;
}