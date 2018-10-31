#include <bits/stdc++.h>

using namespace std;

class DigitStringDiv1 {
public:
    long long count(string, int);
};

long long choose(long long n, long long k) {
    if (k == 0) {
        return 1;
    } else {
        return (n * choose(n - 1, k - 1)) / k;
    }
}

long long DigitStringDiv1::count(string S, int X) {
    string sx(to_string(X));
    int n = S.size();
    int m = sx.size();
    if (m > n) return 0;
    long long res = 0;
    // count number of ways to may longer valid number
    for (int mm = n; mm > m; --mm) {
        for (int i = 0; i < n; ++i) {
            if (S[i] != '0' && n - i - 1 >= mm - 1) {
                res += choose(n - i - 1, mm - 1);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            // let j be the first position were the number is greater than X
            if (S[i] > sx[j] && (n - i - 1) >= (m - j - 1) && i >= j) { 
                // count number of ways to make left part equal to X
                vector<vector<int>> dp(j + 1, vector<int>(i + 1, 0));
                dp[0][0] = 1;
                for (int k = 0; k < j; ++k) {
                    for (int l = 0; l < i; ++l) {
                        if (S[l] == sx[k]) {
                            for (int a = 0; a <= l; ++a)
                                dp[k + 1][l + 1] += dp[k][a];
                        }
                    }
                }
                long long cur = accumulate(begin(dp[j]), end(dp[j]), 0LL);
                // multiply by number of ways to add arbitrary right part
                cur *= choose(n - i - 1, m - j - 1);
                res += cur;
            }
        }
    }
    return res;
}