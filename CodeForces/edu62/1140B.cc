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
        int res1 = 0, res2 = 0;
        for (int i = 0; i < n && s[i] == '<'; ++i, ++res1);
        for (int i = n - 1; i >= 0 && s[i] == '>'; --i, ++res2);
        cout << min(res1, res2) << "\n";
    }
    return 0;
}