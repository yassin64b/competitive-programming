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