#include <bits/stdc++.h>

using namespace std;

class TaskD2 {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        int mx = *max_element(begin(a), end(a));
        stack<int> s;
        for (int i = 0; i < n; ++i) {
            if (a[i] == mx) {
                if (!s.empty()) {
                    out << "NO\n";
                    return;
                }
            } else {
                if (!s.empty() && s.top() == a[i]) {
                    s.pop();
                } else {
                    if (s.empty() || s.top() >= a[i]) {
                        s.push(a[i]);
                    } else {
                        out << "NO\n";
                        return;
                    }
                }
            }
        }
        out << (s.empty() ? "YES\n" : "NO\n");
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskD2 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
