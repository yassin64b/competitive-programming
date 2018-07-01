#include <bits/stdc++.h>

using namespace std;

class TaskA {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<string> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            in >> b[i];
        }
        int res = 0;
        for (int len = 1; len <= 4; ++len) {
            int s = 0, m = 0, l = 0;
            for (const string &t : a) {
                if ((int)t.size() == len) {
                    if (t.back() == 'S') ++s;
                    else if (t.back() == 'M') ++m;
                    else ++l;
                }
            }
            for (const string &t : b) {
                if ((int)t.size() == len) {
                    if (t.back() == 'S') --s;
                    else if (t.back() == 'M') --m;
                    else --l;
                }
            }
            int r1 = 0, r2 = 0;
            if (s < 0) r1 += -s;
            else r2 += s;
            if (m < 0) r1 += -m;
            else r2 += m;
            if (l < 0) r1 += -l;
            else r2 += l;
            assert(r1 == r2);
            res += r1;
        }
        out << res << "\n";
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
