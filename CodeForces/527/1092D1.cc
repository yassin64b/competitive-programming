#include <bits/stdc++.h>

using namespace std;

class TaskD1 {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
            a[i] %= 2;
        }
        stack<int> s;
        for (int i = 0; i < n; ++i) {
            if (!s.empty() && s.top() == a[i]) {
                s.pop();
            } else {
                s.push(a[i]);
            }
        }
        out << (n % 2 == (int)s.size() ? "YES\n" : "NO\n");
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskD1 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
