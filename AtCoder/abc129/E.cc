#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    string L;
    cin >> L;
    int n = L.size();
    constexpr int MOD = 1'000'000'007;
    vector<int> dp1(n + 1, 0), dp2(n + 1, 0);
    dp1[0] = 1;

    for (int i = 0; i < n; ++i) {
        if (L[i] == '1') {
            // set bit in a or in b
            dp1[i + 1] = (dp1[i + 1] + 2LL * dp1[i]) % MOD;
            // don't set the bit
            dp2[i + 1] = (dp2[i + 1] + dp1[i]) % MOD;
        } else {
            dp1[i + 1] = dp1[i];
        }
        dp2[i + 1] = (dp2[i + 1] + 3LL * dp2[i]) % MOD;
    }
    //cout << dp1[n] << " " << dp2[n] << endl;
    cout << (dp1[n] + dp2[n]) % MOD << "\n";


    return 0;
}