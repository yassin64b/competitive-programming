#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

struct line {
    long long m, c;
    long long eval(long long x) { return m * x + c; }
    long double intersectX(line l) { return (long double) (c - l.c) / (l.m - m); }
};


int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    vector<i64> dp(n, 0);
    // Convex Hull Trick CHT adapted from https://codeforces.com/blog/entry/63823
    deque<line> dq;
    dq.push_front({b[0], dp[0]});
    for (int i = 1; i < n; ++i) {
        while (dq.size() >= 2U && dq.back().eval(a[i]) >= dq[dq.size() - 2U].eval(a[i])) {
            dq.pop_back();
        }
        dp[i] = dq.back().eval(a[i]);
        line cur = {b[i], dp[i]};
        while (dq.size() >= 2U && cur.intersectX(dq[0]) <= dq[0].intersectX(dq[1])) {
            dq.pop_front();
        }
        dq.push_front(cur);
    }

    cout << dp[n - 1] << "\n";


    return 0;
}