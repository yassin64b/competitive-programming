#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n;
    cin >> n;
    string s1;
    cin >> s1;
    string s2 = s1;
    vector<int> ops;
    for (int i = 0; i + 1 < n; ++i) {
        if (s1[i] != 'W') {
            s1[i] = 'W';
            s1[i + 1] = (s1[i + 1] == 'W' ? 'B' : 'W');
            ops.push_back(i + 1);
        }
    }
    if (count(begin(s1), end(s1), 'B') == 0) {
        cout << ops.size() << "\n";
        for (int x : ops) {
            cout << x << " ";
        }
        cout << "\n";
        return 0;
    }
    ops.clear();
    for (int i = 0; i + 1 < n; ++i) {
        if (s2[i] != 'B') {
            s2[i] = 'B';
            s2[i + 1] = (s2[i + 1] == 'W' ? 'B' : 'W');
            ops.push_back(i + 1);
        }
    }
    if (count(begin(s2), end(s2), 'W') == 0) {
        cout << ops.size() << "\n";
        for (int x : ops) {
            cout << x << " ";
        }
        cout << "\n";
        return 0;
    }
    cout << -1 << "\n";

    return 0;
}