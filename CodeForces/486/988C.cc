#include <bits/stdc++.h>

using namespace std;

class TaskC {
public:
    void solve(istream& in, ostream& out) {
        int k;
        in >> k;
        vector<vector<int>> a(k);
        map<int, set<int>> m;
        for (int i = 0; i < k; ++i) {
            int n;
            in >> n;
            a[i].resize(n);
            for (int j = 0; j < n; ++j) {
                in >> a[i][j];
            }
            int sum = accumulate(begin(a[i]), end(a[i]), 0);
            for (int j = 0; j < n; ++j) {
                m[sum - a[i][j]].insert(i);
            }
        }
        for (auto [k, v] : m) {
            if (v.size() >= 2U) {
                out << "YES\n";
                int i = *v.begin(), sum = accumulate(begin(a[i]), end(a[i]), 0);
                for (int j = 0; j < (int)a[i].size(); ++j) {
                    if (sum - a[i][j] == k) {
                        out << i + 1 << " " << j + 1 << "\n";
                        break;
                    }
                }
                i = *++v.begin();
                sum = accumulate(begin(a[i]), end(a[i]), 0);
                for (int j = 0; j < (int)a[i].size(); ++j) {
                    if (sum - a[i][j] == k) {
                        out << i + 1 << " " << j + 1 << "\n";
                        break;
                    }
                }
                return;
            }
        }
        out << "NO\n";
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
