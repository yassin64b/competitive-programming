#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n;
    cin >> n;
    string s;
    cin >> s;

    int bal = 0;
    string t = s;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            ++bal;
        } else {
            --bal;
            if (bal < 0) {
                t = s.substr(0, i) + s.substr(i + 1) + s[i];
                break;
            }
        }
    }
    bal = 0;
    for (int i = 0; i < n; ++i) {
        if (t[i] == '(') {
            ++bal;
        } else {
            --bal;
            if (bal < 0) {
                cout << "No\n";
                return 0;
            }
        }
    }
    cout << (bal == 0 ? "Yes" : "No") << "\n";

    return 0;
}