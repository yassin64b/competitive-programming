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
#include <numeric>
#include <cassert>
#include <sstream>
using namespace std;

class aoc7_2 {
private:
    int change(int u, const vector<vector<int>>& g, const vector<int>& w, vector<int>& sumw) {
        sumw[u] = w[u];
        int subw = 0;
        for (int v : g[u]) {
            int tmp = change(v, g, w, sumw);
            if (tmp)
                return tmp;
            subw = sumw[v];
            sumw[u] += sumw[v];
        }
        for (int v : g[u]) {
            if (sumw[v] != subw) {
                cout << w[v] + (subw - sumw[v]) << endl;
                return w[v] + (subw - sumw[v]);
            }
        }
        return 0;
    }
public:
    void solve(istream& in, ostream& out) {
        vector<pair<pair<int, int>, vector<string>>> towers;
        string line;
        map<string, int> mid;
        vector<string> revid;
        int id = 0;
        while (getline(in, line)) {
            stringstream ss(line);
            string name;
            ss >> name;
            mid[name] = id++;
            revid.push_back(name);
            char c;
            ss >> c;
            assert(c == '(');
            int weight;
            ss >> weight;
            ss >> c;
            assert(c == ')');
            ss >> c;
            vector<string> children;
            if (c == '-') {
                ss >> c;
                assert(c == '>');
                string child;
                while (ss >> child) {
                    if (child.back() == ',')
                        child.pop_back();
                    children.push_back(child);
                }
            }
            towers.push_back({{mid[name], weight}, children});
        }
        int n = id;
        vector<vector<int>> g(n);
        vector<int> w(n), sumw(n, 0);
        vector<int> root(n, 1);
        for (int i = 0; i < n; ++i) {
            int u = towers[i].first.first;
            w[u] = towers[i].first.second;
            for (string child : towers[i].second) {
                int v = mid[child];
                g[u].push_back(v);
                root[v] = 0;
            }
        }
        int rootid = -1;
        for (int i = 0; i < n; ++i)
            if (root[i])
                rootid = i;
        out << change(rootid, g, w, sumw) << "\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    aoc7_2 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
