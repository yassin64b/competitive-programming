#include <bits/stdc++.h>

using namespace std;

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

int dfs_cnt = 0;
void dfs_bridge(int u, const vector<vector<int>> &g, set<pair<int, int>> &bridge,
                    vector<int> &low, vector<int> &num, vector<int> &par)
{
    low[u] = num[u] = ++dfs_cnt;
    for (int v : g[u]) {
        if (!num[v]) {
            par[v] = u;
            dfs_bridge(v, g, bridge, low, num, par);
            if (low[v] > num[u]) {
                bridge.emplace(u, v);
                bridge.emplace(v, u);
            }
            low[u] = min(low[u], low[v]);
        } else if (v != par[u]) {
            low[u] = min(low[u], low[v]);
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int, int>> e(m);
    for (int i = 0; i < m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        e[i] = {w, a - 1, b - 1, i};
    }
    sort(begin(e), end(e));
    UnionFind uf(n);
    vector<int> res(m);
    for (int i = 0; i < m; ) {
        int j = i;
        while (j < m && get<0>(e[j]) == get<0>(e[i])) {
            ++j;
        }
        map<int, int> id;
        int cur = 0;
        for (int k = i; k < j; ++k) {
            auto [w, u, v, ind] = e[k];
            if (!uf.is_same_set(u, v)) {
                res[ind] = 1;
                int ru = uf.find_set(u);
                int rv = uf.find_set(v);
                if (!id.count(ru)) id[ru] = cur++;
                if (!id.count(rv)) id[rv] = cur++;
            }
        }
        vector<vector<int>> g(cur);
        multiset<pair<int, int>> edges;
        for (int k = i; k < j; ++k) {
            auto [w, u, v, ind] = e[k];
            if (res[ind] == 1) {
                int ru = uf.find_set(u);
                int rv = uf.find_set(v);
                g[id[ru]].push_back(id[rv]);
                g[id[rv]].push_back(id[ru]);
                edges.emplace(min(id[ru], id[rv]), max(id[ru], id[rv]));
            }
        }
        vector<int> low(cur), num(cur, 0), par(cur, -1);
        set<pair<int, int>> bridge;
        for (int u = 0; u < cur; ++u) {
            if (!num[u]) 
                dfs_bridge(u, g, bridge, low, num, par);
        }
        for (int k = i; k < j; ++k) {
            auto [w, u, v, ind] = e[k];
            int ru = uf.find_set(u);
            int rv = uf.find_set(v);
            if (res[ind] == 1 && bridge.count({id[ru], id[rv]})
                && edges.count({min(id[ru], id[rv]), max(id[ru], id[rv])}) == 1) {
                res[ind] = 2;
            }
        }
        for (int k = i; k < j; ++k) {
            auto [w, u, v, ind] = e[k];
            if (!uf.is_same_set(u, v)) {
                uf.union_set(u, v);
            }
        }

        i = j;
    }

    for (int x : res) {
        if (x == 1) {
            cout << "at least one\n";
        } else if (x == 2) {
            cout << "any\n";
        } else {
            cout << "none\n";
        }
    }

    return 0;
}