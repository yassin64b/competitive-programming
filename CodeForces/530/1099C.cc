#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    string s;
    int k;
    cin >> s >> k;
    int n = s.size();
    constexpr int INF = 2'000;
    int mn_len = 0, mx_len = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '*') {
            --mn_len;
            mx_len = INF;
        } else if (s[i] == '?') {
            --mn_len;
        } else {
            ++mn_len;
            ++mx_len;
        }
    }

    if (mn_len > k || mx_len < k) {
        cout << "Impossible\n";
        return 0;
    }

    int need = k - mn_len;
    string res;
    for (int i = 0; i < n; ++i) {
        if (i + 1 < n && s[i + 1] == '*') {
            res += string(need, s[i]);
            need = 0;
        } else if (i + 1 < n && s[i + 1] == '?') {
            if (need) {
                res += s[i];
                --need;
            }
        } else if (s[i] != '*' && s[i] != '?') {
            res += s[i];
        }
    }
    cout << res << "\n";



    return 0;
}