#include <bits/stdc++.h>

using namespace std;

class TaskD {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            long long cur = a[i];
            set<long long> s;
            vector<long long> res{a[i]};
            for (int j = 0; j < n; ++j) {
                if (j != i) {
                    s.insert(a[j]);
                }
            }
            while (!s.empty()) {
                if (s.count(cur * 2)) {
                    cur *= 2;
                } else if (cur % 3 == 0 && s.count(cur / 3)) {
                    cur /= 3;
                } else {
                    break;
                }
                res.push_back(cur);
                s.erase(cur);
            }
            if (s.empty()) {
                for (long long x : res) {
                    out << x << " ";
                }
                out << "\n";
                return;
            }
        }
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
