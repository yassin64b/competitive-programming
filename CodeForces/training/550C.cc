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

constexpr int MAXV = 100*9;

class C550 {
public:
    void solve(istream& in, ostream& out) {
        string s;
        in >> s;
        int n = s.size();
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            v[i] = s[i] - '0';
        }
        for (int i = 0; i < n; ++i) {
            if (v[i] % 8 == 0) {
                out << "YES\n" << v[i] << "\n";
                return;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                if ((v[i]*10 + v[j]) % 8 == 0) {
                    out << "YES\n" << v[i]*10 + v[j] << "\n";
                    return;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                for (int k = j+1; k < n; ++k) {
                    if ((v[i]*100 + v[j]*10 + v[k]) % 8 == 0) {
                        out << "YES\n" << v[i]*100 + v[j]*10 + v[k] << "\n";
                        return;
                    }
                }
            }
        }
        
        out << "NO\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false);

    C550 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
