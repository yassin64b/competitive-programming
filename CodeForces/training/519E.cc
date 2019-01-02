#include <bits/stdc++.h>

using namespace std;

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

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n;
    cin >> n;
    bin_lift b;
    b.init(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        b.g[u - 1].push_back(v - 1);
        b.g[v - 1].push_back(u - 1);
    }
    int tmp_t = 0;
    b.dfs(0, 0, tmp_t);
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        int ans;
        if (x == y) {
            ans = n;
        } else if (b.is_ancestor(x, y) || b.is_ancestor(y, x)) {
            if (!b.is_ancestor(x, y)) {
                swap(x, y);
            }
            int d = b.dist(x, y);
            if (d % 2 == 0) {
                int w = b.get_node_up(y, d / 2);
                int v = b.get_node_up(y, d / 2 - 1);
                ans = b.sub_sz[w] - b.sub_sz[v];
            } else {
                ans = 0;
            }
        } else {
            int w = b.lca(x, y);
            int d1 = b.dist(x, w), d2 = b.dist(y, w);
            if (d1 == d2) {
                int v1 = b.get_node_up(x, d1 - 1);
                int v2 = b.get_node_up(y, d1 - 1);
                ans = n - b.sub_sz[v1] - b.sub_sz[v2];
            } else {
                int d = d1 + d2;
                if (d % 2 == 0) {
                    if (d1 > d2) {
                        swap(x, y);
                    }
                    int v1 = b.get_node_up(y, d / 2);
                    int v2 = b.get_node_up(y, d / 2 - 1);
                    ans = b.sub_sz[v1] - b.sub_sz[v2];
                } else {
                    ans = 0;
                }
            }
        }
        cout << ans << "\n";
    }
    
    return 0;
}