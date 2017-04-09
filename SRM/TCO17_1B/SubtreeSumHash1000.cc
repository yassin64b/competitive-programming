#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int n;
constexpr int MOD = 1000*1000*1000+7;

int modulo(int a, int b, int c = MOD){
    long long x = 1, y = a;
    while (b > 0){
        if (b%2 == 1){
            x = (x*y) % c;
        }
        y = (y*y) % c;
        b /= 2;
    }
    return x % c;
}

class SubtreeSumHash {
public:
    int count(vector <int>, vector <int>, int);
    
    pair<int, int> dfs(int u, const vector<vector<int>> &g, vector<int> &vis, const vector<int> &weight, const int x) {
        pair<int, int> res{modulo(x, weight[u]), 0}; //first == active, second == closed
        vis[u] = 1;
        for (int v : g[u]) {
            if (!vis[v]) {
                pair<int, int> tmp = dfs(v, g, vis, weight, x);
                res.first += (1LL * tmp.first * res.first) % MOD; //add current vertex to active set
                res.first %= MOD;
                res.second += (tmp.first + tmp.second) % MOD; //close active set + closed set
                res.second %= MOD;
            }
        }
        return res;
    }
};

int SubtreeSumHash::count(vector <int> weight, vector <int> p, int x) {
    n = weight.size();
    vector<vector<int>> g(n);
    for (int i = 0; i < n-1; ++i) {
        g[i+1].push_back(p[i]);
        g[p[i]].push_back(i+1);
    }
    vector<int> vis(n, 0);
    pair<int, int> res = dfs(0, g, vis, weight, x);
    return (res.first + res.second) % MOD;
}