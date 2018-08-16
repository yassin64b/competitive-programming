#include <bits/stdc++.h>

using namespace std;

class DigitRotation {
public:
    int sumRotations(string);
};

const int MOD = 998244353;

int DigitRotation::sumRotations(string X) {
    int n = X.size();
    for (char &c : X) {
        c -= '0';
    }
    vector<long long> v(n, 0);
    v[n - 1] = 1;
    for (int i = n - 2; i >= 0; --i) {
        v[i] = (v[i + 1] * 10LL) % MOD;
    }
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        sum = (sum + X[i] * v[i]) % MOD;
    }
    long long res = 0;
    for (int a = 0; a < n; ++a) {
        for (int b = a + 1; b < n; ++b) {
            for (int c = b + 1; c <  n; ++c) {
                if (a == 0 && X[c] == 0) continue;
                long long tmp = sum;
                tmp -= X[a] * v[a] + X[b] * v[b] + X[c] * v[c];
                tmp += X[c] * v[a] + X[a] * v[b] + X[b] * v[c];
                res = (res + tmp) % MOD;
                res = (res + MOD) % MOD;
            }
        }
    }
    return res;
}