#include <bits/stdc++.h>

using namespace std;

constexpr int INF = 1'000'000'000;

void bfs(const vector<vector<pair<int, int>>> &g, vector<int> &dist, 
         vector<int> &num_broken, vector<int> &par) {
    queue<int> q;
    q.push(0);
    dist[0] = num_broken[0] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto [v, w] : g[u]) {
            if (dist[v] == INF) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
            if (dist[v] == dist[u] + 1) {
                int new_broken = num_broken[u] + (w == 0);
                if (num_broken[v] > new_broken) {
                    num_broken[v] = new_broken;
                    par[v] = u;
                }
            }
        }
    }
}

vector<int> reconstruct(int u, const vector<int> &par) {
    vector<int> path{u};
    int cur = u;
    while (par[cur] != -1) {
        cur = par[cur];
        path.push_back(cur);
    }
    reverse(begin(path), end(path));
    return path;
}

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    set<pair<int, int>> good_edges;
    int cnt_broken = 0;
    for (int i = 0; i < m; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        g[x - 1].emplace_back(y - 1, z);
        g[y - 1].emplace_back(x - 1, z);
        cnt_broken += !z;
        if (z) {
            if (x > y) {
                swap(x, y);
            }
            good_edges.emplace(x - 1, y - 1);
        }
    }
    vector<int> dist(n, INF), num_broken(n, INF), par(n, -1);
    bfs(g, dist, num_broken, par);
    int cnt_blowup = (m - dist[n - 1]) - (cnt_broken - num_broken[n - 1]);
    int cnt_repair = num_broken[n - 1];
    cout << cnt_blowup + cnt_repair << "\n";
    vector<int> path = reconstruct(n - 1, par);
    for (int i = 0; i + 1 < (int)path.size(); ++i) {
        int u = path[i], v = path[i + 1];
        if (u > v) {
            swap(u, v);
        }
        if (pair<int, int> e = {u, v}; !good_edges.count(e)) {
            cout << u + 1 << " " << v + 1 << " " << 1 << "\n";
        } else {
            good_edges.erase(e);
        }
    }
    for (auto [u, v] : good_edges) {
        cout << u + 1 << " " << v + 1 << " " << 0 << "\n";
    }

    return 0;
}