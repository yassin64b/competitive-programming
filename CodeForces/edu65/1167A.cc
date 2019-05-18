#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n;
        string s;
        cin >> n >> s;
        bool ok = false;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '8' && n - i >= 11) {
                ok = true;
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
        
    }

    return 0;
}