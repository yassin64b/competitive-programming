#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n, x, y;
    cin >> n >> x >> y;
    string s;
    cin >> s;
    reverse(begin(s), end(s));
    int res = 0;
    for (int i = 0; i < x; ++i) {
        if (i == y) {
            res += (s[i] == '0');
        } else {
            res += (s[i] == '1');
        }
    }
    cout << res << "\n";
    
    return 0;
}