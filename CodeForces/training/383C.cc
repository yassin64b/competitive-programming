#include <bits/stdc++.h>

using namespace std;

class FenwickTree {
private:
    vector<int> ft;
    int n;
    void update(int a, int v) {
        for ( ; a < (int)ft.size(); a += (a & (-a))) {
            ft[a] += v;
        }
    }
public:
    FenwickTree(int n_) : n(n_) {
        ft.assign(n_ + 1, 0);
    }
    int rsq(int b) {
        int sum = 0;
        for (; b; b -= (b & (-b))) {
            sum += ft[b];
        }
        return sum;
    }
    int rsq(int a, int b) {
        if (a > b) return 0;
        return rsq(b) - rsq(a - 1);
    }
    //NOTE: when using range update, rsq(x) is point query
    void update(int a, int b, int v) {
        update(a, v);
        update(b + 1, -v);
    }
};

void dfs(int u, int &curt0, int &curt1, const vector<vector<int>> &g, 
         vector<int> &ord0, vector<int> &ord1, 
         vector<int> &startt0, vector<int> &endt0,
         vector<int> &startt1, vector<int> &endt1) {
    startt0[u] = ++curt0;
    startt1[u] = curt1 + 1;
    ord0.push_back(u);
    for (int v : g[u]) {
        if (!startt1[v]) {
            dfs(v, curt1, curt0, g, ord1, ord0, startt1, endt1, startt0, endt0);
        }
    }
    endt0[u] = curt0;
    endt1[u] = curt1;
}

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int v, u;
        cin >> v >> u;
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }
    vector<int> ord0, ord1, startt0(n, 0), endt0(n, 0), startt1(n, 0), endt1(n, 0);
    int curt0 = 0, curt1 = 0;
    dfs(0, curt0, curt1, g, ord0, ord1, startt0, endt0, startt1, endt1);

    vector<int> ind(n), lvl(n);
    for (int i = 0; i < (int)ord0.size(); ++i) {
        ind[ord0[i]] = i;
        lvl[ord0[i]] = 0;
    }
    for (int i = 0; i < (int)ord1.size(); ++i) {
        ind[ord1[i]] = i;
        lvl[ord1[i]] = 1;
    }
    FenwickTree ft0(ord0.size()), ft1(ord1.size());
    for (int u = 0; u < n; ++u) {
        if (lvl[u]) {
            ft1.update(ind[u] + 1, ind[u] + 1, a[u]);
        } else {
            ft0.update(ind[u] + 1, ind[u] + 1, a[u]);
        }
    }
    for (int i = 0; i < m; ++i) {
        int type, x;
        cin >> type >> x;
        --x;
        if (type == 1) {
            int val;
            cin >> val;
            if (lvl[x]) {
                val *= -1;
            }
            ft0.update(startt0[x], endt0[x], val);
            ft1.update(startt1[x], endt1[x], -val);
        } else {
            cout << (lvl[x] ? ft1.rsq(ind[x] + 1) : ft0.rsq(ind[x] + 1)) << "\n";
        }
    }
    
    return 0;
}