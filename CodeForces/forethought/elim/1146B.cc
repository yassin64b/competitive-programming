#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    string t;
    cin >> t;
    int n = t.size();
    string s;
    int cnta = 0;
    for (char c : t) {
        if (c != 'a') s += c;
        else ++cnta;
    }
    int m = s.size();
    string res = s.substr(0, m / 2);
    int cnt = 0;
    for (int i = n - 1; i >= 0 && t[i] != 'a'; --i, ++cnt);
    if (s == res + res && cnt >= m / 2) {
        cout << t.substr(0, m / 2 + cnta) << "\n";
    } else {
        cout << ":(\n";
    }

    return 0;
}