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

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> gr(m), inv(n);
    UnionFind uf(n);
    for (int i = 0; i < m; ++i) {
        int k;
        cin >> k;
        gr[i].resize(k);
        for (int j = 0; j < k; ++j) {
            cin >> gr[i][j];
            --gr[i][j];
            inv[gr[i][j]].push_back(i);
        }
        for (int j = 0; j + 1 < k; ++j) {
            uf.union_set(gr[i][j], gr[i][j + 1]);
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << uf.set_sz(i) << " ";
    }
    cout << "\n";


    return 0;
}