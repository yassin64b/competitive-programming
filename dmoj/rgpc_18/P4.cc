#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

class SegmentTree {
private:
    vector<int64> _sum, _d;
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
            _sum[node] = a[l];
        } else {
            build(lc(node), l, mid(l, r), a);
            build(rc(node), mid(l, r) + 1, r, a);
            update(node, l, r);
        }
    }
    void prop(int node) {
        _d[lc(node)] += _d[node];
        _d[rc(node)] += _d[node];
        _d[node] = 0;
    }
    void update(int node, int l, int r) {
        _sum[node] = _sum[lc(node)] + _d[lc(node)] * num(l, mid(l, r))
                      + _sum[rc(node)] + _d[rc(node)] * num(mid(l, r) + 1, r);
    }
    void update_range(int node, int l, int r, int i, int j, int val) {
        if (l > r || l > j || r < i) {
            return;
        } else if (i <= l && r <= j) {
            _d[node] += val;
            return;
        }
        prop(node);
        update_range(lc(node), l, mid(l, r), i, j, val);
        update_range(rc(node), mid(l, r) + 1, r, i, j, val);
        update(node, l, r);
    }
    int64 query_range(int node, int l, int r, int i, int j) {
        if (l > r || l > j || r < i) {
            return 0;
        } else if (i <= l && r <= j) {
            return _sum[node] + _d[node] * num(l, r);
        }
        prop(node);
        int64 res = query_range(lc(node), l, mid(l, r), i, j);
        res += query_range(rc(node), mid(l, r) + 1, r, i, j);
        update(node, l, r);
        return res;
    }
public:
    SegmentTree(const vector<int> &a) : _n(a.size()) {
        _sum.assign(4 * _n + 1, 0);
        _d.assign(4 * _n + 1, 0);
        build(1, 0, _n - 1, a);
    }
    void update_range(int i, int j, int val) {
        update_range(1, 0, _n - 1, i, j, val);
    }
    int64 query_range(int i, int j) {
        return query_range(1, 0, _n - 1, i, j);
    }
};


class dmoj_rgpc18p4 {
public:
    void solve(istream& in, ostream& out) {
        int N, T;
        in >> N >> T;
        vector<int> S(N);
        for (int i = 0; i < N; ++i) {
            in >> S[i];
        }
        SegmentTree st(S);
        
        constexpr int MXV = 200000;
        vector<bool> prime(MXV + 1, true);
        prime[0] = prime[1] = false;
        for (int i = 2; i * i <= MXV; ++i) {
            if (prime[i]) {
                for (int j = i * i; j <= MXV; j += i) {
                    prime[j] = false;
                }
            }
        }
        int64 res = 1000000000000000000LL;
        for (int64 t = 1; t <= T; ++t) {
            int a, b, k;
            in >> a >> b >> k;
            --a;
            --b;
            if (prime[t]) {
                int64 sum = st.query_range(a, b);
                int64 ineff = sum + k;
                res = min(res, t * ineff);
            } else {
                st.update_range(a, b, k);
            }
        }
        out << res << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    dmoj_rgpc18p4 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
