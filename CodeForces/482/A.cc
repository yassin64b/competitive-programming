#include <bits/stdc++.h>

using namespace std;

class TaskA {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> a(n), b;
        set<int> s;
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        for (int i = n - 1; i >= 0; --i) {
            if (!s.count(a[i])) {
                b.push_back(a[i]);
            }
            s.insert(a[i]);
        }
        reverse(begin(b), end(b));
        out << b.size() << "\n";
        for (int x : b) {
            out << x << " ";
        }
        out << "\n";
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
