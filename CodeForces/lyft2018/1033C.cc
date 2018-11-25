#include <bits/stdc++.h>

using namespace std;

class TaskC {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> a(n), inv(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
            inv[a[i] - 1] = i;
        }
        string res(n, 0);
        res[inv[n - 1]] = 'B';
        for (int i = n - 2; i >= 0; --i) {
            int pos = inv[i];
            bool found = false;
            for (int j = pos + a[pos]; j < n; j += a[pos]) {
                if (res[j] == 'B') {
                    found = true;
                }
            }
            for (int j = pos - a[pos]; j >= 0; j -= a[pos]) {
                if (res[j] == 'B') {
                    found = true;
                }
            }
            res[pos] = (found ? 'A' : 'B');
        }
        out << res << "\n";
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
