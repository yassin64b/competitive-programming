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

struct edge {
    int u_, v_, w_;
    edge(int u, int v, int w) : u_(u), v_(v), w_(w) {}
};
class TaskC {
public:
    void solve(istream& in, ostream& out) {
        int n, m;
        in >> n >> m;
        constexpr int prime = 100'069, other = 300'000;
        vector<edge> res;
        for (int i = 1, w = prime; i < n; ++i) {
            if (i != n - 1) {
                res.emplace_back(i, i + 1, 1);
                w -= 1;
            } else {
                res.emplace_back(i, i + 1, w);
            }
            --m;
        }
        int u = 1, v = 3;
        while (m) {
            if (v > n) {
                ++u;
                v = u + 2;
            }
            res.emplace_back(u, v, other);
            --m;
            ++v;
        }
        out << prime << " " << prime << "\n";
        for (const edge &e : res) {
            out << e.u_ << " " << e.v_ << " " << e.w_ << "\n";
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