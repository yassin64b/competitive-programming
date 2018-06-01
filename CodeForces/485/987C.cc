#include <bits/stdc++.h>

using namespace std;

class TaskA {
public:
    void solve(istream& in, ostream& out) {
        map<string, string> m{{"purple", "Power"}, {"green", "Time"},
                              {"blue", "Space"}, {"orange", "Soul"},
                              {"red", "Reality"}, {"yellow", "Mind"}};
        int n;
        in >> n;
        for (int i = 0; i <  n; ++i) {
            string s;
            in >> s;
            m.erase(s);
        }
        out << m.size() << "\n";
        for (auto [k, v] : m) {
            out << v << "\n";
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
