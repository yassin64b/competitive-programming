#include <bits/stdc++.h>

using namespace std;

class A555 {
public:
    void solve(istream& in, ostream& out) {
        int n, k;
        in >> n >> k;
        vector<int> m(k);
        vector<vector<int>> a(k);
        for (int i = 0; i < k; ++i) {
            in >> m[i];
            a[i].resize(m[i]);
            for (int j = 0; j < m[i]; ++j) {
                in >> a[i][j];
            }
        }
        int mx_chain = 0, ind = -1;
        for (int i = 0; i < k; ++i) {
            if (a[i][0] == 1) {
                int cur = 1;
                for (int j = 1; j < m[i]; ++j) {
                    if (a[i][j] != a[i][j - 1] + 1) {
                        break;
                    } else {
                        ++cur;
                    }
                }
                if (cur > mx_chain) {
                    mx_chain = cur;
                    ind = i;
                }
            }
        }
        int num_parts = 0, res = 0;
        for (int i = 0; i < k; ++i) {
            if (i == ind) {
                res += m[i] - mx_chain; // to disassemble
                num_parts += m[i] - mx_chain + 1;
            } else {
                res += m[i] - 1; // to disassemble
                num_parts += m[i];
            }
        }
        out << res + num_parts - 1 << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    A555 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
