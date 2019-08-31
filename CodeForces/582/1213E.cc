#include <bits/stdc++.h>

using namespace std;

bool ok(string res, string s, string t) {
    const int n = res.size();
    assert(s.size() == 2U && t.size() == 2U);
    for (int i = 0; i + 1 < n; ++i) {
        if ((res[i] == s[0] && res[i + 1] == s[1])
            || (res[i] == t[0] && res[i + 1] == t[1])) {
            return false;
        }
    }
    return true;
}
int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n;
    string s, t;
    cin >> n >> s >> t;
    
    for (char c1 = 'a'; c1 <= 'c'; ++c1) {
        for (char c2 = 'a'; c2 <= 'c'; ++c2) {
            if (c1 == c2) continue;
            for (char c3 = 'a'; c3 <= 'c'; ++c3) {
                if (c1 == c3 || c2 == c3) continue;
                string s_interleave;
                for (int i = 0; i < n; ++i) {
                    s_interleave += c1;
                    s_interleave += c2;
                }
                string s_rest(n, c3);
                string s_1 = s_interleave + s_rest;
                string s_2 = s_rest + s_interleave;
                if (ok(s_1, s, t)) {
                    cout << "YES\n" << s_1 << "\n";
                    return 0;
                } else if (ok(s_2, s, t)) {
                    cout << "YES\n" << s_2 << "\n";
                    return 0;
                }
            }
        }
    }
    cout << "NO\n";

    return 0;
}