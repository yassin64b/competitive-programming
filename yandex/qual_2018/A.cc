#include <bits/stdc++.h>

using namespace std;

class yandex_A {
public:
    void solve(istream& in, ostream& out) {
        int a[33]{};
        for (int i = 0; i < 10; ++i) {
            int x;
            in >> x;
            ++a[x];
        }
        int n;
        in >> n;
        for (int i = 0; i < n; ++i) {
            int b[6], cnt = 0;
            for (int j = 0; j < 6; ++j) {
                in >> b[j];
                cnt += a[b[j]];
            }
            out << ((cnt >= 3) ? "Lucky" : "Unlucky") << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    yandex_A solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
