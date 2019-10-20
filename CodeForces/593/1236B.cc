#include <bits/stdc++.h>

using namespace std;
constexpr int MOD = 1'000'000'007;

int modPow(int a, int b, int c = MOD) {
    long long x = 1, y = a;
    while (b > 0) {
        if (b % 2 == 1) {
            x = (x * y) % c;
        }
        y = (y * y) % c;
        b /= 2;
    }
    return x % c;
}

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    int b = modPow(2, m) - 1;
    if (b < 0) b += MOD;
    int c = modPow(b, n);
    cout << c << "\n";

    return 0;
}