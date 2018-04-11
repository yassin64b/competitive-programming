#include <bits/stdc++.h>

using namespace std;

class TaskB {
public:
    void solve(istream& in, ostream& out) {
        int n, a, b;
        in >> n >> a >> b;
        string s;
        in >> s;
        int res = 0;
        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && s[j] == '.') {
                ++j;
            }
            int len = j - i;
            if (a < b) {
                swap(a, b);
            }
            res += min(a, (len + 1) / 2);
            a -= min(a, (len + 1) / 2);
            res += min(b, len / 2);
            b -= min(b, len / 2);
            i = j + 1;
        }
        out << res << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskB solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
