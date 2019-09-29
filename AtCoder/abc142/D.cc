#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    i64 A, B;
    cin >> A >> B;
    int res = 1;
    for (int i = 2; 1LL * i * i <= A; ++i) {
        if (A % i == 0) {
            if (B % i == 0) {
                ++res;
            }
            while (A % i == 0) {
                A /= i;
            }
        }
    }
    if (A > 1 && B % A == 0) {
        ++res;
    }
    cout << res << "\n";

    return 0;
}