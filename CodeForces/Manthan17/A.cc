#include <bits/stdc++.h>

using namespace std;

class TaskA {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        set<string> st;
        for (int i = 0; i < n; ++i) {
            string s;
            in >> s;
            out << (st.count(s) ? "YES" : "NO") << "\n";
            st.insert(s);
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
