#include <bits/stdc++.h>

using namespace std;

int cost(char c, char d) {
    return min(abs(c - d), min(abs('Z' - c) + abs('A' - d) + 1,
                                abs('A' - c) + abs('Z' - d) + 1));
}
int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    string s;
    cin >> s;
    int mn = 1'000;
    for (int i = 0; i + 4 <= n; ++i) {
        int cur = cost(s[i], 'A') + cost(s[i + 1], 'C')
                    + cost(s[i + 2], 'T') + cost(s[i + 3], 'G');
        mn = min(mn, cur);
    }
    cout << mn << endl;

    return 0;
}