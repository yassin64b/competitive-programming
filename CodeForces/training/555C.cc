#include <bits/stdc++.h>

using namespace std;

class SegmentTree {
private:
    vector<int> _mx, _d;
    int _n;
    int lc(int node) { return 2 * node; }
    int rc(int node) { return 2 * node + 1; }
    int mid(int a, int b) { return (a + b) / 2; }
    void prop(int node) {
        _d[lc(node)] = max(_d[lc(node)], _d[node]);
        _d[rc(node)] = max(_d[rc(node)], _d[node]);
        _d[node] = 0;
    }
    void update(int node, int l, int r) {
        _mx[node] = max(max(_mx[lc(node)], _d[lc(node)]), 
                         max(_mx[rc(node)], _d[rc(node)]));
    }
    void update_range(int node, int l, int r, int i, int j, int val) {
        if (l > r || l > j || r < i) {
            return;
        } else if (i <= l && r <= j) {
            _d[node] = max(_d[node], val);
            return;
        }
        prop(node);
        update_range(lc(node), l, mid(l, r), i, j, val);
        update_range(rc(node), mid(l, r) + 1, r, i, j, val);
        update(node, l, r);
    }
    int query_range(int node, int l, int r, int i, int j) {
        if (l > r || l > j || r < i) {
            return 0;
        } else if (i <= l && r <= j) {
            return max(_mx[node], _d[node]);
        }
        prop(node);
        int res = query_range(lc(node), l, mid(l, r), i, j);
        res = max(res, query_range(rc(node), mid(l, r) + 1, r, i, j));
        update(node, l, r);
        return res;
    }
public:
    SegmentTree(int n) : _n(n) {
        _mx.assign(4 * _n + 1, 0);
        _d.assign(4 * _n + 1, 0);
    }
    void update_range(int i, int j, int val) {
        update_range(1, 0, _n - 1, i, j, val);
    }
    int query_range(int i, int j) {
        return query_range(1, 0, _n - 1, i, j);
    }
};

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    vector<tuple<int, int, char>> queries;
    set<int> coords;
    for (int i = 0; i < q; ++i) {
        int x, y;
        char type;
        cin >> x >> y >> type;
        queries.emplace_back(x, y, type);
        coords.insert(x);
        coords.insert(y);
    }
    map<int, int> id, rev;
    int cur_id = 0;
    for (int x : coords) {
        id[x] = ++cur_id;
        rev[cur_id] = x;
    }
    for (int i = 0; i < q; ++i) {
        get<0>(queries[i]) = id[get<0>(queries[i])];
        get<1>(queries[i]) = id[get<1>(queries[i])];
    }

    SegmentTree row(cur_id + 1), col(cur_id + 1);
    for (int i = 0; i < q; ++i) {
        auto [x, y, type] = queries[i];
        if (type == 'U') {
            int upto = col.query_range(x, x);
            cout << rev[y] - rev[upto] << "\n";
            row.update_range(upto + 1, y, x);
            col.update_range(x, x, y);
        } else {
            int upto = row.query_range(y, y);
            cout << rev[x] - rev[upto] << "\n";
            col.update_range(upto + 1, x, y);
            row.update_range(y, y, x);
        }
    } 

    return 0;
}