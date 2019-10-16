#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        int num1 = (a + c - 1) / c;
        int num2 = (b + d - 1) / d;
        if (num1 + num2 <= k) {
            cout << num1 << " " << num2 << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
    return 0;
}