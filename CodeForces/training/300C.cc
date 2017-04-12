#include <iostream>
#include <vector>

using namespace std;

constexpr int MOD = 1000*1000*1000 + 7;

int modPow(long long a, int b, int c = MOD){
    long long x = 1, y = a;
    while (b > 0){
        if (b%2 == 1){
            x = (x*y) % c;
        }
        y = (y*y) % c;
        b /= 2;
    }
    return x % c;
}

int inv(long long x) {
    return modPow(x, MOD-2);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int a, b, n;
    cin >> a >> b >> n;

    vector<int> fac(n+1);
    fac[0] = fac[1] = 1;
    for (int i = 2; i <= n; ++i) {
        fac[i] = (1LL * fac[i-1] * i) % MOD;
    }

    int res = 0;
    for (int i = 0; i <= n; ++i) { //take i times a, n-i times b
        int sod = i * a + (n-i) * b;
        bool exc = true;
        while (exc && sod) {
            if (sod % 10 != a && sod % 10 != b) {
                exc = false;
            }
            sod /= 10;
        }
        if (exc) {
            res += 1LL * fac[n] * inv(1LL * fac[i] * fac[n-i] % MOD) % MOD;
            res %= MOD;
        }
    }
    cout << res << "\n";
    return 0;
}