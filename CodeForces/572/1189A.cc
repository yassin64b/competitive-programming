#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;
    int cnt0 = count(begin(s), end(s), '0');
    if (2 * cnt0 == n) {
        cout << 2 << "\n" << s.substr(0, n - 1) << " " << s.back() << "\n";
    } else {
        cout << 1 << "\n" << s << "\n";
    }

    return 0;
}