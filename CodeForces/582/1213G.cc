#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

class UnionFind {
private:
    vector<int> p, rank, sz;
    int num_sets;
public:
    UnionFind(int N) {
        rank.assign(N, 0);
        p.assign(N, 0);
        sz.assign(N, 1);
        for (int i = 0; i < N; ++i) {
            p[i] = i;
        }
        num_sets = N;
    }
    int find_set(int i) {
        return (p[i] == i) ? i : (p[i] = find_set(p[i]));
    }
    bool is_same_set(int i, int j) {
        return find_set(i) == find_set(j);
    }
    void union_set(int i, int j) {
        if (!is_same_set(i, j)) {
            --num_sets;
            int x = find_set(i), y = find_set(j);
            if (rank[x] > rank[y]) {
                p[y] = x;
                sz[x] += sz[y];
            } else {
                p[x] = y;
                sz[y] += sz[x];
                if (rank[x] == rank[y]) {
                    rank[y]++;
                }
            }
        }
    }
    int num_disjoint_sets() {
        return num_sets;
    }
    int set_sz(int i) {
        int x = find_set(i);
        return sz[x];
    }
};

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> e;
    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        e.emplace_back(w, u - 1, v - 1);
    }
    sort(begin(e), end(e));
    vector<pair<int, int>> q(m);
    for (int i = 0; i < m; ++i) {
        cin >> q[i].first;
        q[i].second = i;
    }
    sort(begin(q), end(q));
    vector<i64> q_ans(m);
    i64 cur_ans = 0;
    UnionFind uf(n);
    for (int i = 0, j = 0; i < m; ++i) {
        while (j < n - 1 && get<0>(e[j]) <= q[i].first) {
            auto [w, u, v] = e[j];
            if (!uf.is_same_set(u, v)) {
                int sz_u = uf.set_sz(u);
                int sz_v = uf.set_sz(v);
                cur_ans += 1LL * sz_u * sz_v;
                uf.union_set(u, v);
            }
            ++j;
        }
        q_ans[q[i].second] = cur_ans;
    }
    for (i64 x : q_ans) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}