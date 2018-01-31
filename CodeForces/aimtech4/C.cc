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

class TaskC {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        vector<int> b(a);
        sort(b.begin(), b.end());
        map<int, int> m_ind;
        for (int i = 0; i < n; ++i) {
            m_ind[b[i]] = i;
        }
        vector<vector<int>> res;
        vector<int> vis(n, 0);
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                res.push_back({});
                int j = i;
                while (!vis[j]) {
                    vis[j] = 1;
                    res.back().push_back(j + 1);
                    j = m_ind[a[j]];
                }
            }
        }
        out << res.size() << "\n";
        for (const auto &v : res) {
            out << v.size();
            for (int x : v) {
                out << " " << x;
            }
            out << "\n";
        }
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskC solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}