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

using namespace std;

class agcA {
public:
    void solve(istream& in, ostream& out) {
        long long A, B, C;
        in >> A >> B >> C;
        
        set<tuple<long long, long long, long long>> vis;
        
        int res = 0;
        while(A % 2 == 0 && B % 2 == 0 && C % 2 == 0) {
            if (vis.find(make_tuple(A, B, C)) != vis.end()) {
                out << -1 << "\n";
                return;
            }
            vis.emplace(A, B, C);
            ++res;
            long long AA = A, BB = B, CC = C;
            A = BB / 2 + CC / 2;
            B = AA / 2 + CC / 2;
            C = AA / 2 + CC / 2;
        }
        
        out << res << "\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    agcA solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
