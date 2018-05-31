#include <bits/stdc++.h>

using namespace std;

class SegmentTree {
private:
    vector<int> _mx, _a;
    int _n;
    int lc(int node) { return 2 * node; }
    int rc(int node) { return 2 * node + 1; }
    int mid(int a, int b) { return (a + b) / 2; }
    int num(int a, int b) { return b - a + 1; }
    void build(int node, int l, int r) {
        if (l == r) {
            _mx[node] = l;
        } else {
            build(lc(node), l, mid(l, r));
            build(rc(node), mid(l, r) + 1, r);
            update(node);
        }
    }
    void update(int node) {
        if (_a[_mx[lc(node)]] > _a[_mx[rc(node)]]) {
            _mx[node] = _mx[lc(node)];
        } else {
            _mx[node] = _mx[rc(node)];
        }
    }
    int query_range(int node, int l, int r, int i, int j) {
        if (l > r || l > j || r < i) {
            return i;
        } else if (i <= l && r <= j) {
            return _mx[node];
        }
        int res1 = query_range(lc(node), l, mid(l, r), i, j);
        int res2 = query_range(rc(node), mid(l, r) + 1, r, i, j);
        return (_a[res1] > _a[res2] ? res1 : res2);
    }
public:
    SegmentTree(vector<int> a, int n) : _a(a), _n(n) {
        _mx.assign(4 * _n + 1, 0);
        build(1, 0, _n - 1);
    }
    int query_range(int i, int j) {
        return query_range(1, 0, _n - 1, i, j);
    }
};

class TaskE {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> a(n);
        for (int i = 0; i < n - 1; ++i) {
            in >> a[i];
            --a[i];
        }
        a[n - 1] = n - 1;
        SegmentTree st(a, n);
        vector<long long> dp(n, 0);
        dp[n - 1] = 0;
        for (int i = n - 2; i >= 0; --i) {
            int m = st.query_range(i, a[i]);
            dp[i] = dp[m] + n - 1 - i - (a[i] - m);
        }
        out << accumulate(begin(dp), end(dp), 0LL) << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskE solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
