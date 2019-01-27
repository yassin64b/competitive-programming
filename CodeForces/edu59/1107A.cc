#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int Q;
    cin >> Q;
    for (int q = 0; q < Q; ++q) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if (n == 2 && s[0] >= s[1]) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            cout << 2 << "\n";
            cout << s[0] << " " << s.substr(1) << "\n";
        }
    }

    return 0;
}