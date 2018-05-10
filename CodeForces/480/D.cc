#include <bits/stdc++.h>

using namespace std;

class TaskD {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
            for (int j = 2; j * j <= abs(a[i]); ++j) {
                while (a[i] % (j * j) == 0) {
                    a[i] /= (j * j);
                }
            }
        }
        map<int, int> ind;
        for (int i = 0, j = 0; i < n; ++i) {
            if (a[i] && !ind.count(a[i])) {
                ind[a[i]] = ++j;
            }
        }
        for (int &x : a) {
            x = ind[x];
        }
        vector<int> res(n, 0);
        for (int i = 0; i < n; ++i) {
            int cur = 0;
            vector<int> cnt(n + 1, 0);
            for (int j = i; j < n; ++j) {
                if (++cnt[a[j]] == 1 && a[j] != 0) {
                    ++cur;
                }
                ++res[max(0, cur - 1)];
            }
        }
        for (int x : res) {
            out << x << " ";
        }
        out << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskD solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
