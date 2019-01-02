struct bin_lift {
    vector<vector<int>> g, up;
    vector<int> t_in, t_out;
    vector<int> sub_sz;
    vector<int> d;
    int l;

    void dfs(int u, int p, int &cur_t) {
        t_in[u] = ++cur_t;
        sub_sz[u] = 1;
        up[u][0] = p;
        for (int i = 1; i <= l; ++i) {
            up[u][i] = up[up[u][i - 1]][i - 1];
        }
        for (int v : g[u]) {
            if (v != p) {
                d[v] = d[u] + 1;
                dfs(v, u, cur_t);
                sub_sz[u] += sub_sz[v];
            }
        }
        t_out[u] = ++cur_t;
    }

    int dist(int u, int v) {
        int w = lca(u, v);
        return d[u] + d[v] - 2 * d[w];
        //return dist_anc(u, w) + dist_anc(v, w);
    }

    /*int dist_anc(int u, int anc) {
        if (u == anc) {
            return 0;
        }
        int d = 0;
        for (int i = l; i >= 0; --i) {
            int w = up[u][i];
            if (!is_ancestor(w, anc)) {
                d += (1 << i);
                u = w;
            }
        }
        return d + 1;
    }*/

    int get_node_up(int u, int d) {
        for (int i = l; i >= 0; --i) {
            if ((1 << i) <= d) {
                d -= (1 << i);
                u = up[u][i];
            }
        }
        return u;
    }

    bool is_ancestor(int u, int v) {
        return (t_in[u] <= t_in[v] && t_out[u] >= t_out[v]);
    }

    int lca(int u, int v) {
        if (is_ancestor(u, v)) {
            return u;
        } else if (is_ancestor(v, u)) {
            return v;
        }
        for (int i = l; i >= 0; --i) {
            int w = up[u][i];
            if (!is_ancestor(w, v)) {
                u = w;
            }
        }
        return up[u][0];
    }

    void init(int n) {
        g.resize(n);
        l = log2(n) + 0.5;
        t_in.resize(n);
        t_out.resize(n);
        up.assign(n, vector<int>(l + 1));
        sub_sz.resize(n);
        d.assign(n, 0);
    }
};