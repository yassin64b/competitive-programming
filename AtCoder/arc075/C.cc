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

class TaskC {
public:
    void solve(istream& in, ostream& out) {
        int N;
        in >> N;
        vector<int> S(N);
        int sum = 0;
        for (int i = 0; i < N; ++i) {
            in >> S[i];
            sum += S[i];
        }
        
        if (sum % 10 == 0) {
            int mn = 100;
            for (int i = 0; i < N; ++i) {
                if (S[i] % 10) {
                    mn = min(mn, S[i]);
                }
            }
            
            if (mn == 100) {
                sum = 0;
            } else {
                sum -= mn;
            }
        }
        out << sum << "\n";
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
