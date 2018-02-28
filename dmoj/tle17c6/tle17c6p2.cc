#include <bits/stdc++.h>

using namespace std;

class tle17c6p2 {
public:
    void solve(istream& in, ostream& out) {
        int N;
        string name;
        in >> N >> name;
        in.ignore();
        for (int i = 0; i < N; ++i) {
            string line;
            getline(in, line);
            stringstream ss(line);
            int x = -1, n = -1;
            char slash = '\0';
            string tname;
            ss >> x >> slash >> n >> tname;
            if (n == -1) {
                out << "Y\n";
            } else if (x <= n) {
                out << "N\n";
            } else {
                if (tname.size() <= name.size()
                    && tname.substr(0, tname.size()) == name.substr(0, tname.size())) {
                    out << "Y\n";
                } else {
                    out << "N\n";
                }
            }
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    tle17c6p2 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
