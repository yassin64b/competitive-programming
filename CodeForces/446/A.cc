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

class TaskA {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i)
            in >> a[i];
        for (int i = 0; i < n; ++i)
            in >> b[i];
        long long sum = accumulate(a.begin(), a.end(), 0LL);
        sort(b.begin(), b.end());
        if (sum > b[n - 1] + b[n - 2]) {
            out << "NO\n";
        } else {
            out << "YES\n";
        }
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    TaskA solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
