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

class dp2 {
public:
    void solve(istream& in, ostream& out) {
        int N;
        in >> N;
        vector<int> R(N, 0), B(N, 0);
        for (int i = 0; i < N; ++i) {
            string s;
            in >> s;
            for (int j = 0; j < (int)s.size(); ++j) {
                R[i] += (s[j] == 'R');
                B[i] += (s[j] == 'B');
            }
        }
        
        vector<vector<int>> ans(101, vector<int>(101, 0));
        for (int i = 0; i < N; ++i) {
            vector<vector<int>> tmp = ans;
            for (int j = 0; j+R[i] <= 100; ++j) {
                for (int k = 0; k+B[i] <= 100; ++k) {
                    tmp[j + R[i]][k + B[i]] = max(tmp[j + R[i]][k + B[i]], ans[j][k] + 1);
                }
            }
            ans = tmp;
        }
        
        
        int Q;
        in >> Q;
        for (int q = 1; q <= Q; ++q) {
            int X, Y;
            in >> X >> Y;
            out << ans[X][Y] << "\n";
        }
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    dp2 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}