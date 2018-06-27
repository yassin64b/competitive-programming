#include <bits/stdc++.h>

using namespace std;

class TaskD {
public:
    void solve(istream& in, ostream& out) {
        int n, m;
        in >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        vector<vector<int>> b(m);
        vector<int> cnt(m, n / m);
        for (int i = 0; i < n; ++i) {
            b[a[i] % m].push_back(i);
        }
        for (int i = 0; i < m; ++i) {
            while (cnt[i] && !b[i].empty()) {
                --cnt[i];
                b[i].pop_back();
            }
        }
        long long res = 0;
        bool crossed = false;
        for (int i = 0, j = 0; i < m; ++i) {
            if (!crossed) j = max(j, i);
            while (!b[i].empty()) {
                while (!cnt[j]) {
                    j = (j + 1) % m;
                    if (j == 0) crossed = true;
                }
                while (cnt[j] && !b[i].empty()) {
                    --cnt[j];
                    int tmp;
                    if (j > i) {
                        tmp = j - i;
                    } else {
                        tmp = m - i + j;
                    }
                    res += tmp;
                    a[b[i].back()] += tmp;
                    b[i].pop_back();
                }
            }
        }
        out << res << "\n";
        for (int x : a) {
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
