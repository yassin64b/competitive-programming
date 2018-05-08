#include <bits/stdc++.h>

using namespace std;

class TaskF {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        map<int, int> m;
        int mx = 0, endv = -1;
        for (int i = 0; i < n; ++i) {
            int need = a[i] - 1;
            if (m.count(need)) {
                m[a[i]] = m[need] + 1;
                //m.erase(need);
            } else {
                m[a[i]] = 1;
            }
            if (m[a[i]] > mx) {
                mx = m[a[i]];
                endv = a[i];
            }
        }
        vector<int> res;
        for (int i = n - 1; i >= 0; --i) {
            if (a[i] == endv) {
                res.push_back(i + 1);
                --endv;
            }
        }
        reverse(begin(res), end(res));
        out << res.size() << "\n";
        for (int x : res) {
            out << x << " ";
        }
        out << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskF solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
