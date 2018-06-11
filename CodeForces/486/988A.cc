#include <bits/stdc++.h>

using namespace std;

class TaskA {
public:
    void solve(istream& in, ostream& out) {
        int n, k;
        in >> n >> k;
        set<int> cur;
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            int a;
            in >> a;
            if (!cur.count(a)) {
                cur.insert(a);
                res.push_back(i + 1);
            }
        }
        if ((int)res.size() < k) {
            out << "NO\n";
        } else {
            out << "YES\n";
            for (int i = 0; i < k; ++i) {
                out << res[i] << " ";
            }
            out << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskA solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
