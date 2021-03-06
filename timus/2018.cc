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
#include <cassert>

using namespace std;

constexpr int MOD = 1e9 + 7;

class timus2018 {
public:
    void solve(istream& in, ostream& out) {
        int n, a, b;
        in >> n >> a >> b;
        
        vector<int> end_a(a+1, 0), end_b(b+1, 0);
        end_a[1] = end_b[1] = 1;
        
        for (int len = 2; len < n+1; ++len) {
            int sum_a = 0;
            for (int i = 1; i < a+1; ++i) {
                sum_a = (sum_a + end_a[i]) % MOD;
            }
            
            for (int i = a; i >= 1; --i) {
                end_a[i] = end_a[i-1];
            }
            for (int i = 1; i < b+1; ++i) {
                end_a[1] = (end_a[1] + end_b[i]) % MOD;
            }
            
            for (int i = b; i >= 1; --i) {
                end_b[i] = end_b[i-1];
            }
            end_b[1] = (end_b[1] + sum_a) % MOD;
        }
        int res = 0;
        for (int j = 1; j < a+1; ++j) {
            res = (res + end_a[j]) % MOD;
            //out << end_a[j] << " ";
        }
        //out << endl;
        for (int j = 1; j < b+1; ++j) {
            res = (res + end_b[j]) % MOD;
            //out << end_b[j] << " ";
        }
        //out << endl;
        out << res << endl;
    }
};


int main() {
    std::ios::sync_with_stdio(false);

    timus2018 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
