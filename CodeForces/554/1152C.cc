#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

i64 lcm(int a, int b) {
    return a / gcd(a, b) * (i64)b;
}

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int a, b;
    cin >> a >> b;
    int d = abs(b - a);

    int mn_k = 0;
    i64 mn_lcm = lcm(a, b);
    for (int y = 1; y * y <= d; ++y) {
        if (d % y != 0) {
            continue;
        }
        for (int x : {y, d / y}) {
            int k = 0;
            if (a % x != 0) {
                k = x - (a % x);
            }
            i64 cur_lcm = lcm(a + k, b + k);
            if (cur_lcm < mn_lcm || (cur_lcm == mn_lcm && k < mn_k)) {
                mn_k = k;
                mn_lcm = lcm(a + k, b + k);
            }
        }
        
    }
    cout << mn_k << "\n";

    return 0;
}