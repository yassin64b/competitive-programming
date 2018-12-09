#include <bits/stdc++.h>

using namespace std;

class MaximizingGCD {
public:
    int maximumGCDPairing(vector <int>);
};

bool check(vector<int> A, int n, int r, int k) {
    bool ok = true;
    vector<int> taken(n, 0);
    taken[0] = taken[k] = 1;
    for (int i = 0; i < n && ok; ++i) {
        if (!taken[i]) {
            for (int j = i + 1; j < n; ++j) {
                if (!taken[j] && (A[i] + A[j]) % r == 0) {
                    taken[i] = taken[j] = 1;
                    break;
                }
            }
            ok = taken[i];
        }
    }
    return ok;
}

int MaximizingGCD::maximumGCDPairing(vector <int> A) {
    int n = A.size();
    int res = 0;
    for (int k = 1; k < n; ++k) {
        int sum = A[0] + A[k];
        for (int r = 1; r * r <= sum; ++r) {
            if (sum % r == 0) {
                if (check(A, n, r, k)) res = max(res, r);
                if (check(A, n, sum / r, k)) res = max(res, sum / r);
            }
        }
    }
    return res;
}