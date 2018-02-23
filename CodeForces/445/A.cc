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
        int a[6];
        for (int i = 0; i < 6; ++i)
            in >> a[i];
        int sum = 0;
        for (int i = 0; i < 6; ++i)
            sum += a[i];
        for (int i = 0; i < 6; ++i)
            for (int j = i + 1; j < 6; ++j)
                for (int k = j + 1; k < 6; ++k)
                    if (2 * (a[i] + a[j] + a[k]) == sum) {
                        out << "YES\n";
                        return;
                    }
                
        out << "NO\n";
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
