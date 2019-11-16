#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n, x, a, b;
        cin >> n >> x >> a >> b;
        cout << min(n - 1, abs(a - b) + x) << "\n";
    }
    return 0;
}