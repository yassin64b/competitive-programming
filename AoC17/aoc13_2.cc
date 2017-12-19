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

class aoc13_2 {
public:
    void solve(istream& in, ostream& out) {
        string s;
        vector<pair<int, int>> firewall;
        while (getline(in, s)) {
            stringstream ss(s);
            char trash;
            int depth, range;
            ss >> depth >> trash >> range;
            firewall.emplace_back(depth, range);
        }
        for (int start = 0; ; ++start) {
            bool ok = true;
            for (int i = 0; ok && i < (int)firewall.size(); ++i) {
                int guard = (start + firewall[i].first) % (2 * firewall[i].second - 2);
                if (guard == 0)
                    ok = false;
            }
            if (ok) {
                out << start << "\n";
                return;
            }
        }
        
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    aoc13_2 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
