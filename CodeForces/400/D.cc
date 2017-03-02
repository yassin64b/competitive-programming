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

class D776 {
public:
    void solve(istream& in, ostream& out) {
        int n, m;
        in >> n >> m;
        vector<int> r(n);
        for (int i = 0; i < n; ++i) {
            in >> r[i];
        }
        vector<vector<int>> x(m), inv(n);
        for (int i = 0; i < m; ++i) {
            int len;
            in >> len;
            x[i].resize(len);
            for (int j = 0; j < len; ++j) {
                in >> x[i][j];
                inv[x[i][j]-1].push_back(i);
            }
        }
        
        UnionFind uf(2*m+2);
        for (int i = 0; i < n; ++i) {
            assert(inv[i].size() == 2);
            assert(inv[i][0] != inv[i][1]);
            
            if (r[i] == 0) { //either switch 1 uneven, switch 2 even no. times toggled or vice versa
                uf.unionSet(inv[i][0], inv[i][1]+m);
                uf.unionSet(inv[i][0]+m, inv[i][1]);
            } else { //both even no. times toggled or both uneven
                uf.unionSet(inv[i][0], inv[i][1]);
                uf.unionSet(inv[i][0]+m, inv[i][1]+m);
            }
        }
        
        for (int i = 0; i < m; ++i) {
            if (uf.isSameSet(i, i+m)) {
                out << "NO\n";
                return;
            }
        }
        out << "YES\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false);

    D776 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
