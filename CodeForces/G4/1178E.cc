#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();
    string t1;
    for (int i = 0; i + 1 < n / 2; i += 2) {
        char c = 'a';
        if (s[i] == s[n - 1 - i] || s[i] == s[n - 1 - i - 1]) {
            c = s[i];
        } else {
            c = s[i + 1];
        }
        t1 += c;
    }
    string t2 = t1;
    reverse(begin(t2), end(t2));
    if ((int)(t1.size() + t2.size()) < n / 2) t1 += s[n / 2];
    cout << t1 << t2 << "\n";

    return 0;
}