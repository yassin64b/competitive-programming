#include <bits/stdc++.h>

using namespace std;

class A573 {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        /*vector<pair<int, int>> p_divs; // overcomplicated manual prime factorization check
        for (int i = 2; i * i <= a[0]; ++i) {
            if (a[0] % i == 0) {
                p_divs.emplace_back(i, 0);
                while (a[0] % i == 0) {
                    ++p_divs.back().second;
                    a[0] /= i;
                }
            }
        }
        if (a[0] > 1) {
            p_divs.emplace_back(a[0], 1);
        }
        for (int i = 1; i < n; ++i) {
            for (const auto &p : p_divs) {
                if (p.first != 2 && p.first != 3) {
                    for (int j = 0; j < p.second; ++j) {
                        if (a[i] % p.first != 0) {
                            out << "No\n";
                            return;
                        }
                        a[i] /= p.first;
                    }
                }
            }
            if (a[i] > 1) {
                while (a[i] % 2 == 0) a[i] /= 2;
                while (a[i] % 3 == 0) a[i] /= 3;
            }
            if (a[i] != 1) {
                out << "No\n";
                return;
            }
        }*/
        for (int i = 0; i < n; ++i) {
            while (a[i] % 2 == 0) a[i] /= 2;
            while (a[i] % 3 == 0) a[i] /= 3;
            if (i > 0 && a[i] != a[i - 1]) {
                out << "No\n";
                return;
            }
        }
        out << "Yes\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    A573 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
