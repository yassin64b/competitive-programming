#include <bits/stdc++.h>

using namespace std;

class SegmentTree {
private:
    // a = number of correct bracket seq
    // b = number of unused opening brackets
    // c = number of unused closing brackets
    vector<int> _a, _b, _c;
    int _n;
    int lc(int node) { return 2 * node; }
    int rc(int node) { return 2 * node + 1; }
    int mid(int a, int b) { return (a + b) / 2; }
    int num(int a, int b) { return b - a + 1; }
    void build(int node, int l, int r, const string &a) {
        if (l == r) {
            _a[node] = 0;
            _b[node] = (a[l] == '(');
            _c[node] = (a[l] == ')');
        } else {
            build(lc(node), l, mid(l, r), a);
            build(rc(node), mid(l, r) + 1, r, a);
            update(node);
        }
    }
    void update(int node) {
        int c1 = lc(node), c2 = rc(node);
        int num_new = min(_b[c1], _c[c2]);
        _a[node] = _a[c1] + _a[c2] + num_new;
        _b[node] = _b[c1] + _b[c2] - num_new;
        _c[node] = _c[c1] + _c[c2] - num_new;
    }
    tuple<int, int, int> query_range(int node, int l, int r, int i, int j) {
        if (l > r || l > j || r < i) {
            return tuple(0, 0, 0);
        } else if (i <= l && r <= j) {
            return tuple(_a[node], _b[node], _c[node]);
        }
        auto [a1, b1, c1] = query_range(lc(node), l, mid(l, r), i, j);
        auto [a2, b2, c2] = query_range(rc(node), mid(l, r) + 1, r, i, j);
        int num_new = min(b1, c2);
        return tuple(a1 + a2 + num_new, b1 + b2 - num_new, c1 + c2 - num_new);
    }
public:
    SegmentTree(const string &a) : _n(a.size()) {
        _a.assign(4 * _n + 1, 0);
        _b.assign(4 * _n + 1, 0);
        _c.assign(4 * _n + 1, 0);
        build(1, 0, _n - 1, a);
    }
    int query_range(int i, int j) {
        return get<0>(query_range(1, 0, _n - 1, i, j));
    }
};

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    string s;
    cin >> s;
    SegmentTree st(s);
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        cout << 2 * st.query_range(l - 1, r - 1) << "\n";
    }   

    return 0;
}