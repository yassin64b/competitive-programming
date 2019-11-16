#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int x, y;
        cin >> x >> y;
        if (x <= 1) {
            cout << (y <= x ? "YES" : "NO") << "\n";
        } else if (x <= 3) {
            cout << (y <= 3 ? "YES" : "NO") << "\n";
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}