#include <bits/stdc++.h>

using namespace std;

class TaskC {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> l(n), r(n);
        for (int i = 0; i < n; ++i) {
            in >> l[i];
        }
        for (int i = 0; i < n; ++i) {
            in >> r[i];
        }
        for (int i = 0; i < n; ++i) {
            if (l[i] > i || r[i] > n - 1 - i) {
                out << "NO\n";
                return;
            }
        }
        vector<int> res(n, 0);
        for (int i = 1; i <= n; ++i) {
            int mx = -1, ind = -1;
            for (int j = 0; j < n; ++j) {
                if (res[j] == 0 && l[j] + r[j] > mx) {
                    ind = j;
                    mx = l[j] + r[j];
                }
            }
            if (ind == -1) {
                break;
            }
            for (int j = 0; j < n; ++j) {
                if (res[j] == 0 && l[j] + r[j] == mx) {
                    res[j] = i;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            int cnt1 = 0, cnt2 = 0;
            for (int j = 0; j < n; ++j) {
                cnt1 += (j < i && res[j] > res[i]);
                cnt2 += (j > i && res[j] > res[i]);
            }
            if (cnt1 != l[i] || cnt2 != r[i]) {
                out << "NO\n";
                return;
            }
        }
        out << "YES\n";
        for (int x : res) {
            out << x << " ";
        }
        out << "\n";
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
