#include <bits/stdc++.h>

using namespace std;

constexpr int INF = 1000000001;

class SegmentTree {
private:
    vector<int> _min, _d;
    int _n;
    int lc(int node) {
        return 2 * node;
    }
    int rc(int node) {
        return 2 * node + 1;
    }
    int mid(int a, int b) {
        return (a + b) / 2;
    }
    int num(int a, int b) {
        return b - a + 1;
    }
    void build(int node, int l, int r, const vector<int> &a) {
        if (l == r) {
            _min[node] = a[l];
        } else {
            build(lc(node), l, mid(l, r), a);
            build(rc(node), mid(l, r) + 1, r, a);
            update(node, l, r);
        }
    }
    void prop(int node) {
        _d[lc(node)] = min(_d[lc(node)], _d[node]);
        _d[rc(node)] = min(_d[rc(node)], _d[node]);
        _d[node] = INF;
    }
    void update(int node, int l, int r) {
        _min[node] = min(min(_min[lc(node)], _d[lc(node)]),
                         min(_min[rc(node)], _d[rc(node)]));
    }
    void update_range(int node, int l, int r, int i, int j, int val) {
        if (l > r || l > j || r < i) {
            return;
        } else if (i <= l && r <= j) {
            _d[node] = min(_d[node], val);
            return;
        }
        prop(node);
        update_range(lc(node), l, mid(l, r), i, j, val);
        update_range(rc(node), mid(l, r) + 1, r, i, j, val);
        update(node, l, r);
    }
    int query_range(int node, int l, int r, int i, int j) {
        if (l > r || l > j || r < i) {
            return INF;
        } else if (i <= l && r <= j) {
            return min(_min[node], _d[node]);
        }
        prop(node);
        int res = query_range(lc(node), l, mid(l, r), i, j);
        res = min(res, query_range(rc(node), mid(l, r) + 1, r, i, j));
        update(node, l, r);
        return res;
    }
public:
    SegmentTree(const vector<int> &a) : _n(a.size()) {
        _min.assign(4 * _n + 1, INF);
        _d.assign(4 * _n + 1, INF);
        build(1, 0, _n - 1, a);
    }
    void update_range(int i, int j, int val) {
        update_range(1, 0, _n - 1, i, j, val);
    }
    int query_range(int i, int j) {
        return query_range(1, 0, _n - 1, i, j);
    }
};

class apac_stretch_rope {
public:
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        for (int t = 1; t <= T; ++t) {
            int N, M, L;
            in >> N >> M >> L;
            vector<int> a(N), b(N), p(N);
            for (int i = 0; i < N; ++i) {
                in >> a[i] >> b[i] >> p[i];
            }
            vector<int> dp(L + 1, INF);
            dp[0] = 0;
            for (int i = 0; i < N; ++i) {
                for (int j = L - a[i]; j >= 0; --j) {
                    //for (int k = b[i]; k >= a[i]; --k) { // slower
                    //    if (j + k <= L) {
                    //        dp[j + k] = min(dp[j + k], dp[j] + p[i]);
                    //    }
                    //}
                    for (int k = min(L, j + b[i]); k >= j + a[i]; --k) {
                        dp[k] = min(dp[k], dp[j] + p[i]);
                    }       
                }
            }
            int res = dp[L];

            // slow segtree = better complexity
            // practically slightly slower than above solution
            /*SegmentTree dp(vector<int>(L + 1, INF)); 
            dp.update_range(0, 0, 0);
            for (int i = 0; i < N; ++i) {
                for (int j = L - a[i]; j >= 0; --j) {
                    int dp_j = dp.query_range(j, j);
                    dp.update_range(j + a[i], min(L, j + b[i]), p[i] + dp_j);
                }
            }
            int res = dp.query_range(L, L);*/

            out << "Case #" << t << ": " << (res >= M ? "IMPOSSIBLE\n" : to_string(res) + "\n");
            out.flush();
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    apac_stretch_rope solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
