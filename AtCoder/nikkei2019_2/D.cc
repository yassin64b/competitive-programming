#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
constexpr i64 INF = 1e18;

class SegmentTree {
private:
    vector<i64> _mx;
    int _n;
    int lc(int node) { return 2 * node; }
    int rc(int node) { return 2 * node + 1; }
    int mid(int a, int b) { return (a + b) / 2; }
    int num(int a, int b) { return b - a + 1; }
    void update(int node) {
        _mx[node] = min(_mx[lc(node)], _mx[rc(node)]);
    }
    void update_range(int node, int l, int r, int i, i64 val) {
        if (l > r || l > i || r < i) {
            return;
        } else if (i == l && i == r) {
            _mx[node] = min(_mx[node], val);
            return;
        }
        update_range(lc(node), l, mid(l, r), i, val);
        update_range(rc(node), mid(l, r) + 1, r, i, val);
        update(node);
    }
    i64 query_range(int node, int l, int r, int i, int j) {
        if (l > r || l > j || r < i) {
            return INF;
        } else if (i <= l && r <= j) {
            return _mx[node];
        }
        i64 res = query_range(lc(node), l, mid(l, r), i, j);
        return min(res, query_range(rc(node), mid(l, r) + 1, r, i, j));
    }
public:
    SegmentTree(int n) : _n(n) {
        _mx.assign(4 * _n + 1, INF);
        //build(1, 0, _n - 1, a);
    }
    void update(int i, i64 val) {
        update_range(1, 0, _n - 1, i, val);
    }
    i64 query_range(int i, int j) {
        return query_range(1, 0, _n - 1, i, j);
    }
};

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    SegmentTree st(N + 1);
    vector<tuple<int, int, int>> segs(M);
    for (int i = 0; i < M; ++i) {
        int l, r, c;
        cin >> l >> r >> c;
        segs[i] = tuple<int,int,int>{r, l, c};
    }
    sort(begin(segs), end(segs));
    st.update(1, 0);
    for (int i = 0; i < M; ++i) {
        int r, l, c;
        tie(r, l, c) = segs[i];
        i64 mn = st.query_range(l, r);
        st.update(r, mn + c);
    }
    i64 ans = st.query_range(N, N);
    if (ans < INF) {
        cout << ans << "\n";
    } else {
        cout << -1 << "\n";
    }
    return 0;
}