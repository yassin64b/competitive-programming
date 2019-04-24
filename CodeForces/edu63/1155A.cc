#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n;
    string s;
    cin >> n >> s;
    for (int i = 0; i + 1 < n; ++i) {
        if (s[i + 1] < s[i]) {
            cout << "YES\n" << i + 1 << " " << i + 2 << "\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}