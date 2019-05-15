#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n;
    string s;
    cin >> n >> s;
    string res;
    res += s[0];
    for (int i = 1; i < n; ++i) {
        if (res.size() % 2) {
            if (s[i] != res.back()) {
                res += s[i];
            }
        } else {
            res += s[i];
        }
    }
    if (res.size() % 2) {
        res.pop_back();
    }
    cout << s.size() - res.size() << "\n";
    cout << res << "\n";

    return 0;
}