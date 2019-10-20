#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int a, b, c;
        cin >> a >> b >> c;
        int res = 0;
        while (b >= 1 && c >= 2) {
            --b;
            c -= 2;
            res += 3;
        }
        while (a >= 1 && b >= 2) {
            --a;
            b -= 2;
            res += 3;
        }
        cout << res << "\n";
    }
    return 0;
}