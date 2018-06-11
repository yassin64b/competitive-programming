#include <bits/stdc++.h>

using namespace std;

class TaskB {
private:
    bool is_substr(const string &s, const string &t) {
        int n = s.size(), m = t.size();
        for (int i = 0; i + n <= m; ++i) {
            if (s == t.substr(i, n)) {
                return true;
            }
        }
        return false;
    }
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<string> v(n);
        for (int i = 0; i < n; ++i) {
            in >> v[i];
        }
        sort(begin(v), end(v), [](const string &s, const string &t) {
            return s.size() < t.size();
        });
        for (int i = 1; i < n; ++i) {
            if (!is_substr(v[i - 1], v[i])) {
                out << "NO\n";
                return;
            }
        }
        out << "YES\n";
        for (const string &s : v) {
            out << s << "\n";
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
