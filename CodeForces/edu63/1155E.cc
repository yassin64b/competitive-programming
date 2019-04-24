#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 1'000'003;

int modPow(int a, int b = MOD - 2, int c = MOD) {
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

int query(int x) {
    cout << "? " << x << endl;
    int f;
    cin >> f;
    if (f == -1) exit(0);
    return f;
}
int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    constexpr int NUM = 10;
    vector<int> f(NUM + 1);
    for (int k = 0; k <= 10; ++k) {
        f[k] = query(k);
    }
    vector<int> mult(NUM + 1);
    for (int i = 0; i <= NUM; ++i) {
        long long tmp = 1;
        for (int j = 0; j <= NUM; ++j) {
            if (i != j) {
                tmp *= (i - j);
            }
        }
        mult[i] = 1LL * modPow(tmp) * f[i] % MOD;
    }
    for (int x = 0; x < 1'000'003; ++x) {
        int res = 0;
        for (int i = 0; i <= NUM; ++i) {
            int tmp = 1;
            for (int j = 0; j <= NUM; ++j) {
                if (i != j) {
                    tmp = 1LL * tmp * (x - j) % MOD;
                }
            }
            res = (res + 1LL * mult[i] * tmp) % MOD;
        }
        if (res == 0) {
            cout << "! " << x << endl;
            return 0;
        }
    }
    cout << "! -1" << endl;

    return 0;
}