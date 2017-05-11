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

constexpr int MOD = 1000 * 1000 * 1000 + 7;

class kickA {
public:
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        
        for (int t = 1; t <= T; ++t) {
            int N;
            in >> N;
            vector<int> K(N), v(N+1);
            for (int i = 0; i < N; ++i) {
                in >> K[i];
            }
            sort(K.begin(), K.end());
            
            v[1] = 1;
            for (int i = 2; i <= N; ++i) {
                v[i] = (2LL * v[i-1]) % MOD;
            }
            
            long long res = 0;
            for (int i = 0; i < N; ++i) {
                for (int j = i+1; j < N; ++j) {
                    res += (1LL * v[j - i] * (K[j] - K[i])) % MOD;
                    res %= MOD;
                }
            }
            out << "Case #" << t << ": " << res << "\n";
        }
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    kickA solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
