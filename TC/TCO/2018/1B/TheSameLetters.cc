#include <bits/stdc++.h>

using namespace std;

class ThreeSameLetters {
public:
    int countStrings(int, int);
};

const int MOD = 1000000007;

int ThreeSameLetters::countStrings(int L, int S) {
    // dp1[i][j] num ways up to i with next character not j without a block
    // dp2[i][j] num ways up to i with next character not j with one block
    vector<vector<int>> dp1(L + 1, vector<int>(S + 1, 0));
    vector<vector<int>> dp2(L + 1, vector<int>(S + 1, 0));
    dp1[0][S] = 1;
    for (int i = 0; i < L; ++i) {
        for (int j = 0; j <= S; ++j) {
            for (int k = 0; k < S; ++k) {
                if (k == j) continue;
                
                dp1[i + 1][k] += dp1[i][j], dp1[i + 1][k] %= MOD;
                if (i + 2 <= L) dp1[i + 2][k] += dp1[i][j], dp1[i + 2][k] %= MOD;
                
                if (i + 3 <= L) dp2[i + 3][k] += dp1[i][j], dp2[i + 3][k] %= MOD;
                
                dp2[i + 1][k] += dp2[i][j], dp2[i + 1][k] %= MOD;
                if (i + 2 <= L) dp2[i + 2][k] += dp2[i][j], dp2[i + 2][k] %= MOD;
            }
        }
    } 
    int res = 0;
    for (int j = 0; j < S; ++j) {
        res = (res + dp2[L][j]) % MOD;
    }
    return res;
}