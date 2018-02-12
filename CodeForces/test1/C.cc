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
    void build(int node, int l, int r, const vector<int> &a) {
        if (l == r) {
            _sum[node] = a[l];
        } else {
            build(lc(node), l, mid(l, r), a);
            build(rc(node), mid(l, r) + 1, r, a);
            update(node);
        }
    }
    void prop(int node) {
        _d[lc(node)] += _d[node];
        _d[rc(node)] += _d[node];
        _d[node] = 0;
    }
    void update(int node) {
        _sum[node] = min(_sum[lc(node)] + _d[lc(node)], _sum[rc(node)] + _d[rc(node)]);
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
        update(node);
    }
    int64 query_range(int node, int l, int r, int i, int j) {
        if (l > r || l > j || r < i) {
            return 2'000'000'000'000'000'000LL;
        } else if (i <= l && r <= j) {
            return _sum[node] + _d[node];
        }
        prop(node);
        int64 res = query_range(lc(node), l, mid(l, r), i, j);
        res = min(res, query_range(rc(node), mid(l, r) + 1, r, i, j));
        update(node);
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


class test1 {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        SegmentTree st(a);
        int m;
        in >> m;
        in.ignore();
        for (int i = 0; i < m; ++i) {
            string line;
            getline(in, line);
            stringstream ss(line);
            int lf, rg, v;
            ss >> lf >> rg;
            if (ss >> v) {
                if (lf > rg) {
                    st.update_range(lf, n - 1, v);
                    st.update_range(0, rg, v);
                } else {
                    st.update_range(lf, rg, v);
                }
            } else {
                if (lf > rg) {
                    out << min(st.query_range(lf, n - 1), st.query_range(0, rg));
                } else {
                    out << st.query_range(lf, rg);
                }
                out << "\n";
            }
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    test1 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
