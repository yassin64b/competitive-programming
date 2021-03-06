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
        int N;
        in >> N;
        vector<int> a(3*N);
        for (int i = 0; i < 3*N; ++i) {
            in >> a[i];
        }
        sort(a.begin(), a.end(), greater<int>());
        long long sum = 0;
        for (int i = 0, j = 3*N-1; i < 2*N && j >= 2*N; i += 2, --j) {
            sum += a[i+1];
        }
        out << sum << "\n";
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
