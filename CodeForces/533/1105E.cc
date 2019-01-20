#include <bits/stdc++.h>

using namespace std;

int solve_poly(vector<int> &exist, vector<set<int>> &g) {
    int n = g.size();
    int mn_deg = n + 1;
    for (int u = 0; u < n; ++u) {
        if (exist[u]) {
            mn_deg = min(mn_deg, (int)g[u].size());
        }
    }
    for (int u = 0; u < n; ++u) {
        if (exist[u] && (int)g[u].size() == mn_deg) {
            exist[u] = 0;
            for (int v : g[u]) {
                exist[v] = 0;
            }
            vector<int> to_erase(g[u].begin(), g[u].end());
            for (int v : to_erase) {
                for (int w : g[v]) {
                    g[w].erase(v);
                }
                g[v].clear();
            }
            g[u].clear();
            return solve_poly(exist, g) + 1;
        }
    }
    return 0;
}

int branch_mx_deg(vector<int> exist, vector<set<int>> g) {
    int n = g.size();
    int mx_deg = 0;
    for (int u = 0; u < n; ++u) {
        if (exist[u]) {
            mx_deg = max(mx_deg, (int)g[u].size());
        }
        
    }
    if (mx_deg <= 2) {
        int sz = solve_poly(exist, g);
        return sz;
    }

    for (int u = 0; u < n; ++u) {
        if (exist[u] && (int)g[u].size() == mx_deg) {
            vector<int> to_erase;
            for (int v : g[u]) {
                to_erase.push_back(v);
            }

            for (int v : g[u]) {
                g[v].erase(u);
            }
            g[u].clear();
            exist[u] = 0;
            int sz = branch_mx_deg(exist, g);
            
            for (int v : to_erase) {
                for (int w : g[v]) {
                    g[w].erase(v);
                }
                g[v].clear();
                exist[v] = 0;
            }
            sz = max(sz, branch_mx_deg(exist, g) + 1);
            return sz;
        }
    }
    assert(false);
    return -1;
}



int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    int cur_id = 0;
    map<string, int> id;
    set<int> cur;
    vector<set<int>> g(m);
    for (int i = 0; i < n; ++i) {
        int type;
        cin >> type;
        if (type == 1) {
            for (int u : cur) {
                for (int v : cur) {
                    if (u != v) {
                        g[u].insert(v);
                        g[v].insert(u);
                    }
                }
            }
            cur.clear();
        } else {
            assert(type == 2);
            string s;
            cin >> s;
            if (!id.count(s)) {
                id[s] = cur_id++;
            }
            int j = id[s];
            cur.insert(j);
        }
    }
    for (int u : cur) {
        for (int v : cur) {
            if (u != v) {
                g[u].insert(v);
                g[v].insert(u);
            }
        }
    }

    vector<int> exist(m, 1);
    cout << branch_mx_deg(exist, g) << "\n";
    
    return 0;
}