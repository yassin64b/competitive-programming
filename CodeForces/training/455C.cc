/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author yassin
 */

#include <fstream>

#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#include <tuple>
#include <queue>
#include <functional>
#include <stack>
#include <cassert>

using namespace std;

class UnionFind {
private:
    vector<int> p, rank;
    int numSets;
public:
    UnionFind(int N) {
        rank.assign(N, 0);
        p.assign(N, 0);
        for (int i = 0; i < N; ++i) {
            p[i] = i;
        }
        numSets = N;
    }
    
    int findSet(int i) {
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }
    
    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }
    
    void unionSet(int i, int j) {
        if (!isSameSet(i, j)) {
            --numSets;
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) {
                p[y] = x;
            } else {
                p[x] = y;
                if (rank[x] == rank[y]) {
                    rank[y]++;
                }
            }
        }
    }
    
    int numDisjointSets() {
        return numSets;
    }
};

class C455 {
private:
    pair<int, int> dfs(int u, const vector<vector<int>> &g, vector<int> &vis) {
        vis[u] = 1;
        pair<int, int> res = make_pair(u, 0);
        for (int i = 0; i < (int)g[u].size(); ++i) {
            int v = g[u][i];
            if (!vis[v]) {
                pair<int, int> tmp = dfs(v, g, vis);
                if (tmp.second+1 > res.second) {
                    res = tmp;
                    ++res.second;
                }
            }
        }
        return res;
    }

public:
    void solve(istream &in, ostream &out) {
        int n, m, q;
        in >> n >> m >> q;
        
        UnionFind uf(n);
        vector<vector<int>> g(n);
        for (int i = 0; i < m; ++i) {
            int a, b;
            in >> a >> b;
            g[a - 1].push_back(b - 1);
            g[b - 1].push_back(a - 1);
            uf.unionSet(a - 1, b - 1);
        }
        
        vector<int> diameter(n, 0), vis1(n, 0), vis2(n, 0);
        for (int i = 0; i < n; ++i) {
            if (!vis1[uf.findSet(i)]) {
                pair<int, int> b = dfs(i, g, vis1);
                pair<int, int> c = dfs(b.first, g, vis2);
                diameter[uf.findSet(i)] = c.second;
                //cout << "diameter " << i+1 << " " << c.second << endl;
            }
        }
        
        for (int i = 0; i < q; ++i) {
            int c, x;
            in >> c >> x;
            if (c == 1) {
                out << diameter[uf.findSet(x-1)] << "\n";
            } else {
                int y, s1, s2;
                in >> y;
                s1 = uf.findSet(x-1);
                s2 = uf.findSet(y-1);
                if (s1 != s2) {
                    int newdia = max(diameter[s1], diameter[s2]);
                    newdia = max(newdia, (int)ceil(diameter[s1]/2.)+(int)ceil(diameter[s2]/2.)+1);
                    uf.unionSet(s1, s2);
                    //cout << "old dias: " << diameter[s1] << " " << diameter[s2] << endl;
                    //cout << "merge " << s1+1 << " " << s2+1 << " -> " << newdia << endl;
                    diameter[uf.findSet(s1)] = newdia;
                }
                
            }
        }
    }
};


int main() {
    std::ios::sync_with_stdio(false);

    C455 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
