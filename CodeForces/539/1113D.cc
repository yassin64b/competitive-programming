#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 1; i < n; ++i) {
        string a = s.substr(0, i);
        string b = s.substr(i);
        string new_s(b + a);
        string rev(new_s);
        reverse(begin(rev), end(rev));
        if (new_s == rev && new_s != s) {
            cout << 1 << "\n";
            return 0;
        }
    }
    for (int i = 1; i <= n / 2; ++i) {
        string a = s.substr(0, i);
        string b = s.substr(n - i);
        if (a + b != b + a) {
            cout << 2 << "\n";
            return 0;
        }
    }
    cout << "Impossible\n";

    return 0;
}