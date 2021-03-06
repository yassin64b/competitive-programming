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

class coci_olivander {
public:
    void solve(istream& in, ostream& out) {
        int N;
        in >> N;
        vector<int> X(N), Y(N);
        for (int i = 0; i < N; ++i) {
            in >> X[i];
        }
        for (int i = 0; i < N; ++i) {
            in >> Y[i];
        }
        sort(X.begin(), X.end());
        sort(Y.begin(), Y.end());
        for (int i = 0; i < N; ++i) {
            if (X[i] > Y[i]) {
                out << "NE\n";
                return;
            }
        }
        out << "DA\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    coci_olivander solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
