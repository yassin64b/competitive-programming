#include <bits/stdc++.h>

using namespace std;

class TaskE {
private:
    void dfs(int u, const vector<vector<pair<int, int>>> &g,
            vector<int> &vis, vector<vector<tuple<int, int, int>>> &p1,
            vector<vector<pair<int, int>>> &p2)
    {
        vis[u] = 1;
        for (auto [v, d] : g[u]) {
            if (!vis[v]) {
                dfs(v, g, vis, p1, p2);
                p2[u].push_back(p2[v][0]);
                p2[u].back().first += d;
            }
        }
        if (p2[u].empty()) {
            p2[u].emplace_back(0, u);
        } else {
            sort(begin(p2[u]), end(p2[u]));
            reverse(begin(p2[u]), end(p2[u]));
            if (p2[u].size() >= 2U) {
                p1[u].emplace_back(p2[u][0].first + p2[u][1].first, p2[u][0].second, p2[u][1].second);
            }
        }
    }
    bool dfs(int u, int dest, const vector<vector<pair<int, int>>> &g,
            vector<int> &vis, vector<int> &path)
    {
        vis[u] = 1;
        path.push_back(u);
        if (u == dest) {
            return true;
        }
        for (auto [v, d] : g[u]) {
            if (!vis[v]) {
                if (dfs(v, dest, g, vis, path)) {
                    return true;
                }
            }
        }
        path.pop_back();
        return false;
    }
    void dfs(int u, const vector<vector<pair<int, int>>> &g,
            vector<int> &vis, vector<int> &subdist)
    {
        vis[u] = 1;
        subdist[u] = 0;
        for (auto [v, d] : g[u]) {
            if (!vis[v]) {
                dfs(v, g, vis, subdist);
                subdist[u] = max(subdist[u], subdist[v] + d);
            }
        }
    }
    int get_mid(vector<int> path, int len, vector<vector<pair<int, int>>> &g) {
        map<pair<int, int>, int> ecost;
        for (int u = 0; u < (int)g.size(); ++u) {
            for (auto [v, d] : g[u]) {
                ecost[pair(u, v)] = d;
            }
        }
        int n = path.size(), cur = 0;
        int mn = len, u = path[0];
        for (int i = 0; i + 1 < n; ++i) {
            cur += ecost[pair(path[i], path[i + 1])];
            int mx = max(cur, len - cur);
            if (mx < mn) {
                mn = mx;
                u = path[i + 1];
            }
        }
        return u;
    }
public:
    void solve(istream& in, ostream& out) {
        int n, k;
        in >> n >> k;
        vector<vector<pair<int, int>>> g(n);
        for (int i = 0; i < n - 1; ++i) {
            int u, v, d;
            in >> u >> v >> d;
            g[u - 1].emplace_back(v - 1, d);
            g[v - 1].emplace_back(u - 1, d);
        }
        vector<int> vis(n, 0);
        vector<vector<pair<int, int>>> p2(n);
        vector<vector<tuple<int, int, int>>> p1(n);
        dfs(0, g, vis, p1, p2);
        tuple<int, int, int> lp{-1, 0, 0};
        for (int u = 0; u < n; ++u) {
            for (auto tp : p1[u]) {
                lp = max(lp, tp);
            }
            for (auto p : p2[u]) {
                auto tp = tuple(p.first, p.second, u);
                lp = max(lp, tp);
            }
        }
        auto [_d, x, y] = lp;
        vis.assign(n, 0);
        vector<int> path;
        dfs(x, y, g, vis, path);
        int start = get_mid(path, _d, g);
        vis.assign(n, 0);
        vector<int> subdist(n, 0);
        dfs(start, g, vis, subdist);
        set<tuple<int, int, int>> cur;
        for (auto [v, d] : g[start]) {
            cur.emplace(subdist[v] + d, start, v);
        }
        vector<int> res{start};
        vector<int> num(n, 0);
        for (int j = 1; j < k && !cur.empty(); ++j) {
            auto [d, u, v] = *cur.rbegin();
            ++num[u];
            ++num[v];
            if (num[u] == 2) {
                for (auto [w, tmp_d] : g[u]) {
                    cur.erase(tuple(subdist[w] + tmp_d, u, w));
                }
            } else {
                cur.erase(tuple(d, u, v));
            }
            for (auto [w, tmp_d] : g[v]) {
                if (num[w] == 0) {
                    cur.emplace(subdist[w] + tmp_d, v, w);
                }
            }
            res.push_back(v);
        }
        vis.assign(n, 0);
        priority_queue<pair<int, int>> pq;
        for (int u : res) {
            pq.emplace(-0, u);
        }
        int mx = 0;
        while (!pq.empty()) {
            int d = -pq.top().first, u = pq.top().second;
            pq.pop();
            if (vis[u]) continue;
            mx = max(mx, d);
            vis[u] = 1;
            for (auto [v, tmp_d] : g[u]) {
                if (!vis[v]) {
                    pq.emplace(-(d + tmp_d), v);
                }
            }
        }
        out << mx << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskE solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
