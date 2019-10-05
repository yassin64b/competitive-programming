#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int l, r;
    cin >> l >> r;
    for (int i = l; i <= r; ++i) {
        string s(to_string(i));
        set<char> ss(begin(s), end(s));
        if (ss.size() == s.size()) {
            cout << i << "\n";
            return 0;
        }
    }
    cout << -1 << "\n";
    
    return 0;
}