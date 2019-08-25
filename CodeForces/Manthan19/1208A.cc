#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int a, b, n;
        cin >> a >> b >> n;
        
        if (n % 3 == 0) {
            cout << a << "\n";
        } else if (n % 3 == 1) {
            cout << b << "\n";
        } else {
            cout << (a ^ b) << "\n";
        }
    }
    return 0;
}