#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <utility>
using namespace std;

set<pair<int, int>> bridges;
int counter;

void dfs1(int u, const vector<vector<int>>& g, vector<int>& par, vector<int>& low, vector<int>& num) {
    low[u] = num[u] = counter++;
    for (int v : g[u]) {
        if (!num[v]) {
            par[v] = u;
            dfs1(v, g, par, low, num);
            if (low[v] > num[u]) {
                bridges.emplace(u, v);
                bridges.emplace(v, u);
            }
            low[u] = min(low[u], low[v]);
        } else if (v != par[u]) {
            low[u] = min(low[u], num[v]);    
        }
    }
}

bool dfs2(int u, int goal, const vector<vector<int>>& g, vector<int>& vis) {
    vis[u] = 1;
    if (u == goal)
        return true;
    for (int v : g[u]) {
        if (!vis[v]) {
            bool found = dfs2(v, goal, g, vis);
            if (found && bridges.find(make_pair(u, v)) != bridges.end())
                return true;
        }
    }
    return false;
}

int main() 
{
    ios::sync_with_stdio(false);
    
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<vector<int>> g(N);
    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    counter = 1;
    vector<int> num(N, 0), low(N, 0), par(N, 0);
    for (int i = 0; i < N; ++i)
        if (!num[i]) dfs1(i, g, par, low, num);
    for (int q = 0; q < Q; ++q) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        vector<int> vis(N, 0);
        cout << dfs2(x, y, g, vis) << endl;
    }
    
    return 0;
}