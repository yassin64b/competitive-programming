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

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pair<int,int>> vii;

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

class TaskC {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        
        UnionFind uf(n);
        vector<int> p(n), b(n);
        for (int i = 0; i < n; ++i) {
            in >> p[i];
            uf.unionSet(i, p[i]-1);
        }
        int cnt1 = 0;
        for (int i = 0; i < n; ++i) {
            in >> b[i];
            cnt1 += (b[i] == 1);
        }
        int res = 0;
        if (cnt1 % 2 == 0) {
            ++res;
        }
        
        if (uf.numDisjointSets() == 1) {
            out << res << endl;
        } else {
            res += uf.numDisjointSets();
            out << res << endl;
        }
    }
};


int main() {
    std::ios::sync_with_stdio(false);

    TaskC solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
