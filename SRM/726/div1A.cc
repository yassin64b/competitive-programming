#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

class Unpacking {
public:
    int getcost(vector <int>, vector <int>, vector <int>, int);
};
int Unpacking::getcost(vector <int> a, vector <int> b, vector <int> cost, int K) {
    int n = a.size();
    int MX = 0;
    for (int i = 0; i < n; ++i)
        MX += cost[i];
    vector<vector<int>> dp(MX + 1, vector<int>(n + 1));
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int k = i; k >= 0; --k) {
            for (int j = 0; j + cost[i] <= MX; ++j) {
                dp[j + cost[i]][k + 1] = max(dp[j + cost[i]][k + 1], dp[j][k] + a[i]);
            }
        }
    }
    int res = 1000 * 1000 * 1000;
    bool ok = false;
    for (int i = 0; !ok && i <= MX; ++i) {
        for (int k = 0; !ok && k <= n; ++k) {
            if (dp[i][k] >= K + k)  {
                res = i;
                ok = true;
            }
        }
    }
    dp.assign(MX + 1, vector<int>(n + 1));
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int k = i; k >= 0; --k) {
            for (int j = 0; j + cost[i] <= MX; ++j) {
                dp[j + cost[i]][k + 1] = max(dp[j + cost[i]][k + 1], dp[j][k] + b[i]);
            }
        }
    }
    ok = false;
    for (int i = 0; !ok && i <= MX; ++i) {
        for (int k = 0; !ok && k <= n; ++k) {
            if (dp[i][k] >= K + k) {
                res = min(res, i);
                ok = true;
            }
        }
    }
    dp.assign(MX + 1, vector<int>(n + 1));
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int k = i; k >= 0; --k) {
            for (int j = 0; j + cost[i] <= MX; ++j) {
                dp[j + cost[i]][k + 1] = max(dp[j + cost[i]][k + 1], dp[j][k] + a[i] + b[i]);
            }
        }
    }
    ok = false;
    for (int i = 0; !ok && i <= MX; ++i) {
        for (int k = 0; !ok && k <= n; ++k) {
            if (dp[i][k] >= 2 * K - 1) {
                res = min(res, i);
                ok = true;
            }
        }
    }
    if (res == 1000 * 1000 * 1000) res = -1;
    return res;
}