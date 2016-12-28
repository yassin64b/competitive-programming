#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int dfs(int i, vector<vector<int>> &g, vector<int> &vis, vector<int> &cc)
{
    vis[i] = true;
    cc.push_back(i);

    int sum = 0;
    for (size_t j = 0; j < g[i].size(); ++j) {
        if (!vis[g[i][j]]) {
            sum += dfs(g[i][j], g, vis, cc);
        }
    }
    return sum + 1;
}

int main()
{
    ios::sync_with_stdio(false);

    int N, K, L;
    cin >> N >> K >> L;

    vector<vector<int>> road(N), rail(N);
    for (int i = 0; i < K; ++i) {
        int p, q;
        cin >> p >> q;
        road[p-1].push_back(q-1);
        road[q-1].push_back(p-1);
    }
    for (int i = 0; i < L; ++i) {
        int r, s;
        cin >> r >> s;
        rail[r-1].push_back(s-1);
        rail[s-1].push_back(r-1);
    }

    vector<int> vis(N, 0), res(N, -1);
    vector<vector<int>> cc1;
    vector<int> cc1val;
    map<int, int> mcc1, mcc2;
    for (int i = 0; i < N; ++i) {
        if (!vis[i]) {
            cc1.push_back(vector<int>());
            cc1val.push_back(dfs(i, road, vis, cc1[cc1.size()-1]));
            int x = cc1.size() - 1;
            for (size_t j = 0; j < cc1[x].size(); ++j) {
                mcc1[cc1[x][j]] = x;
            }
            sort(cc1[x].begin(), cc1[x].end());
        }
    }

    vis.assign(N, 0);
    vector<vector<int>> cc2;
    vector<int> cc2val;
    for (int i = 0; i < N; ++i) {
        if (!vis[i]) {
            cc2.push_back(vector<int>());
            cc2val.push_back(dfs(i, rail, vis, cc2[cc2.size()-1]));
            int x = cc2.size() - 1;
            for (size_t j = 0; j < cc2[x].size(); ++j) {
                mcc2[cc2[x][j]] = x;
            }
            sort(cc2[x].begin(), cc2[x].end());
        }
    }

    for (int i = 0; i < N; ++i) {
        if (cc1val[mcc1[i]] == 1) {
            res[i] = 1;
        }
    }
    for (int i = 0; i < N; ++i) {
        if (cc2val[mcc2[i]] == 1) {
            res[i] = 1;
        }
    }

    for (int i = 0; i < N; ++i) {
        if (res[i] == -1) {
            vector<int> intersection;
            set_intersection(cc1[mcc1[i]].begin(), cc1[mcc1[i]].end(),
                             cc2[mcc2[i]].begin(), cc2[mcc2[i]].end(),
                             back_inserter(intersection));
            for (size_t j = 0; j < intersection.size(); ++j) {
                res[intersection[j]] = intersection.size();
            }
            if (res[i] == -1) {
                res[i] = 1;
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        cout << res[i] << " ";
    }

    return 0;
}