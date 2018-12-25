#include <bits/stdc++.h>

using namespace std;

class TaskB {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> a(n);
        vector<vector<int>> inv(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
            inv[a[i]].push_back(i);
        }
        vector<int> b(n), cnt(n + 1, 0);
        for (int i = 0, col = 0; i < n; ++i) {
            for (int j = 0, cur = 0; j < (int)inv[i].size(); ++j) {
                if (cur == 0) {
                    cur = n - i;
                    ++col;
                }
                if (col > n) break;
                b[inv[i][j]] = col;
                ++cnt[col];
                --cur;
            }
        }
        bool ok = true;
        for (int i = 0; ok && i < n; ++i) {
            if (b[i] > n || n - cnt[b[i]] != a[i]) {
                ok = false;
            }
        }
        if (ok) {
            out << "Possible\n";
            for (int x : b) {
                out << x << " ";
            }
            out << "\n";
        } else {
            out << "Impossible\n";
        }
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
