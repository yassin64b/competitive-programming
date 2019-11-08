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
    void union_set(int i, int j, set<int> &roots) {
        if (!is_same_set(i, j)) {
            --num_sets;
            int x = find_set(i), y = find_set(j);
            if (rank[x] > rank[y]) {
                p[y] = x;
                sz[x] += sz[y];
                roots.erase(y);
            } else {
                p[x] = y;
                sz[y] += sz[x];
                if (rank[x] == rank[y]) {
                    rank[y]++;
                }
                roots.erase(x);
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
    vector<set<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u - 1].insert(v - 1);
        g[v - 1].insert(u - 1);
    }
    set<int> roots;
    UnionFind uf(n);
    for (int u = 0; u < n; ++u) {
        map<int, int> m;
        for (int x : roots) {
            m[x] = 0;
        }
        roots.insert(u);
        for (int v : g[u]) {
            if (v < u) {
                ++m[uf.find_set(v)];
            }
        }
        for (auto [k, v] : m) {
            if (v < uf.set_sz(k)) {
                uf.union_set(u, k, roots);
            }
        }
    }
    cout << uf.num_disjoint_sets() - 1 << "\n";
    

    return 0;
}