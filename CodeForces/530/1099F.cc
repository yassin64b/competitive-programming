#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int hibit(unsigned int n) {
    n |= (n >>  1);
    n |= (n >>  2);
    n |= (n >>  4);
    n |= (n >>  8);
    n |= (n >> 16);
    return n - (n >> 1);
}

class FenwickTree {
private:
    vector<i64> ft;
    int n, msb;
public:
    FenwickTree(int n_) : n(n_) {
        ft.assign(n + 1, 0);
        msb = hibit(n);
    }
    i64 rsq(int b) {
        i64 sum = 0;
        for (; b; b -= (b & (-b))) {
            sum += ft[b];
        }
        return sum;
    }
    i64 rsq(int a, int b) {
        if (a > b) return 0;
        return rsq(b) - rsq(a - 1);
    }
    void update(int a, i64 v) {
        for ( ; a < (int)ft.size(); a += (a & (-a))) {
            ft[a] += v;
        }
    }
    int upper_bound(i64 s) {
        int pos = 0;
        for (int bs = msb; bs > 0; bs /= 2) {
            int nxt = bs + pos;
            if (nxt <= n && s >= ft[nxt]) {
                s -= ft[nxt];
                pos = nxt;
            }
        }
        return min(pos + 1, n);
    }
};

void dfs(int u, int p, i64 T, const vector<vector<pair<int, i64>>> &g,
         vector<i64> &res, const vector<i64> &x, const vector<i64> &t,
         FenwickTree &ft_time, FenwickTree &ft_cnt) {
    ft_time.update(t[u], x[u] * t[u]);
    ft_cnt.update(t[u], x[u]);
    
    int mx_t = ft_time.upper_bound(T); // maximum t for a cookie I choose
    i64 overshoot_x = ft_cnt.rsq(mx_t, mx_t); // number of cookies available with t = mx_t
    i64 used_T = ft_time.rsq(mx_t); // total time used for all cookies upto mx_t
    used_T -= overshoot_x * mx_t; // without cookies with t = mx_t
    i64 left_T = T - used_T; // time left for eating the cookies with t = mx_t
    res[u] = ft_cnt.rsq(mx_t) - overshoot_x + min(overshoot_x, left_T / mx_t);

    for (auto [v, w] : g[u]) {
        if (v != p) {
            dfs(v, u, T - 2 * w, g, res, x, t, ft_time, ft_cnt);
        }
    }

    ft_time.update(t[u], -x[u] * t[u]);
    ft_cnt.update(t[u], -x[u]);
}

i64 dfs(int u, int p, const vector<vector<pair<int, i64>>> &g, 
         const vector<i64> &res) {
    i64 b1 = 0, b2 = 0;
    for (auto [v, w] : g[u]) {
        if (v != p) {
            i64 cur = dfs(v, u, g, res);
            if (cur > b1) {
                b2 = b1;
                b1 = cur;
            } else if (cur > b2) {
                b2 = cur;
            }
        }
    }
    return max(res[u], (u == 0 ? b1 : b2));
}

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n;
    i64 T;
    cin >> n >> T;
    vector<i64> x(n), t(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }
    vector<vector<pair<int, i64>>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int p, l;
        cin >> p >> l;
        --p;
        g[p].emplace_back(i + 1, l);
    }

    constexpr int MXV = 1'000'000;
    vector<i64> res(n);
    FenwickTree ft_time(MXV), ft_cnt(MXV);
    dfs(0, -1, T, g, res, x, t, ft_time, ft_cnt);

    i64 mx = dfs(0, -1, g, res);
    cout << mx << "\n";

    return 0;
}