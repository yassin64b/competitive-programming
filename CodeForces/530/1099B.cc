#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    int res = 2'000'000'000;
    for (int d1 = 1; d1 * d1 <= n; ++d1) {
        int d2 = (n + d1 - 1) / d1;
        res = min(res, d1 + d2);
    }
    cout << res << "\n";

    return 0;
}