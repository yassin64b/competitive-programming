#include <bits/stdc++.h>

using namespace std;

class C950 {
public:
    void solve(istream& in, ostream& out) {
        string s;
        in >> s;
        int n = s.size();
        vector<vector<int>> res;
        set<int> a, b;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                if (b.empty()) {
                    a.insert(res.size());
                    res.push_back({i});
                } else {
                    res[*b.begin()].push_back(i);
                    a.insert(*b.begin());
                    b.erase(b.begin());
                }
            } else {
                if (a.empty()) {
                    out << -1 << "\n";
                    return;
                } else {
                    res[*a.begin()].push_back(i);
                    b.insert(*a.begin());
                    a.erase(a.begin());
                }
            }
        }
        if (!b.empty()) {
            out << -1 << "\n";
            return;
        }
        out << res.size() << "\n";
        for (const auto &v : res) {
            out << v.size();
            for (int x : v) {
                out << " " << x + 1;
            }
            out << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    C950 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
