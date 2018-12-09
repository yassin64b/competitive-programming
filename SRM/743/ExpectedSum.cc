#include <bits/stdc++.h>

using namespace std;

class ExpectedSum {
public:
    double solve(vector <int>, vector <int>);
};

double ExpectedSum::solve(vector <int> seq, vector <int> pm) {
    const int MXV = 50 * 50;
    const int n = seq.size();
    vector<double> p(n);
    for (int i = 0; i < n; ++i) {
        p[i] = pm[i] / 100.;
    }
    double res = 0;
    vector<vector<double>> dp(MXV + 1, vector<double>(MXV + 1, 0.));
    vector<vector<double>> nxt(MXV + 1, vector<double>(MXV + 1, 0.));
    dp[0][0] = 1.;
    for (int i = 0; i < n; ++i) {
        for (int sum = 0; sum <= MXV; ++sum) {
            for (int cur = 0; cur <= sum && cur + seq[i] <= MXV; ++cur) {
                nxt[sum][max(0, cur - seq[i])] += p[i] * dp[sum][cur];
                nxt[max(sum, cur + seq[i])][cur + seq[i]] += (1. - p[i]) * dp[sum][cur];
            }
        }
        for (int sum = 0; sum <= MXV; ++sum) {
            for (int cur = 0; cur <= sum; ++cur) {
                dp[sum][cur] = nxt[sum][cur];
                nxt[sum][cur] = 0;
            }
        }
    }
    for (int sum = 0; sum <= MXV; ++sum) {
        for (int cur = 0; cur <= sum; ++cur) {
            res += sum * dp[sum][cur];
        }
    }
    return res;
}