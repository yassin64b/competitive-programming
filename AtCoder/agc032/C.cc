#include <bits/stdc++.h>

using namespace std;

int dfs(int u, int t, int k, vector<vector<int>> &g, vector<map<int, int>> &cap, vector<int> &vis, int id) {
    if (u == t) {
        return k;
    }
    vis[u] = id;
    for (int v : g[u]) {
        if (vis[v] != id && cap[u][v] >= k) {
            int add = dfs(v, t, k, g, cap, vis, id);
            if (add == k) {
                cap[u][v] -= k;
                cap[v][u] += k;
                return add;
            }
        }
    }
    return 0;
}
int augment(int s, int t, int k, vector<vector<int>> &g, vector<map<int, int>> &cap) {
    int cur = 0;
    int add = 1, it = 0;
    int n = g.size();
    vector<int> vis(n, 0);
    while (add) {
        add = dfs(s, t, k, g, cap, vis, ++it);
        cur += add;
    }
    return cur;
}
int maxflow(int s, int t, vector<vector<int>> &g, vector<map<int, int>> &cap) {
    int flow = 0;
    for (int k = 1; k > 0; k >>= 1) {
        flow += augment(s, t, k, g, cap);
    }
    return flow;
}
void add_edge(int u, int v, vector<vector<int>> &g, vector<map<int, int>> &cap) {
    g[u].push_back(v);
    g[v].push_back(u);
    cap[u][v] += 1;
    cap[v][u] += 1;
}

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;
    vector<vector<int>> g(N);
    vector<map<int, int>> cap(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        add_edge(a - 1, b - 1, g, cap);
    }
    
    vector<int> cnt4;
    int cnt6 = 0;
    bool ok = true;
    for (int u = 0; ok && u < N; ++u) {
        if (g[u].size() >= 4U) {
            cnt4.push_back(u);
        }
        cnt6 += (g[u].size() >= 6U);
        if (g[u].size() % 2 != 0) {
            ok = false;
        }
    }
    if (ok && cnt4.size() == 2U) {
        int flow = maxflow(cnt4[0], cnt4[1], g, cap);
        if (flow > 2) {
            ok = false;
        }
    }
    cout << ((ok && (cnt4.size() >= 2U || cnt6 >= 1)) ? "Yes" : "No") << "\n";
    

    return 0;
}