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

class aoc2_2 {
public:
    void solve(istream& in, ostream& out) {
        string s;
        int res = 0;
        while (getline(in, s)) {
            stringstream ss(s);
            vector<int> v;
            {
                int x;
                while (ss >> x)
                    v.push_back(x);
            }
            for (int i = 0; i < (int)v.size(); ++i)
                for (int j = i + 1; j < (int)v.size(); ++j)
                    if (max(v[i], v[j]) % min(v[i], v[j]) == 0)
                        res += max(v[i], v[j]) / min(v[i], v[j]);
        }
        out << res << "\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    aoc2_2 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
