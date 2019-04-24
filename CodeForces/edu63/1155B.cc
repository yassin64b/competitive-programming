#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n;
    string s;
    cin >> n >> s;
    const int num_moves = (n - 11) / 2;
    string a;
    int i, j;
    for (i = 0, j = num_moves; i < n && j > 0; --j) {
        while (i + j < n && s[i] == '8') {
            a += s[i];
            ++i;
        }
        ++i;
    }
    while (i < n) a += s[i++];
    int cnt = 0;
    for (int j = 0; j < (int)a.size() && a[j] == '8'; ++j, ++cnt);
    if (cnt > num_moves) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}