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

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

class TaskC {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            in >> a[i];
        int mn = -1;
        for (int i = 0; i < n; ++i) {
            int curgcd = a[i];
            for (int j = i; j < n; ++j) {
                curgcd = gcd(curgcd, a[j]);
                if (curgcd == 1) {
                    if (mn == -1)
                        mn = j - i;
                    mn = min(mn, j - i);
                }
            }
        }
        if (mn == -1) {
            out << -1 << "\n";
        } else {
            int cnt = 0;
            for (int i = 0; i < n; ++i)
                cnt += a[i] != 1;
            if (cnt < n)
                out << cnt << "\n";
            else
                out << mn + n - 1 << "\n";
        }
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
