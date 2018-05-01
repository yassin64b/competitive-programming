#include <bits/stdc++.h>

using namespace std;

class TaskC {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<tuple<int, int, int>> v(n);
        for (int i = 0; i < n; ++i) {
            in >> get<0>(v[i]) >> get<1>(v[i]);
            get<1>(v[i]) *= -1;
            get<2>(v[i]) = i;
        }
        sort(begin(v), end(v));
        
        int mx_r = 0, ind = -1;
        for (int i = 0; i < n; ++i) {
            auto [l, r, j] = v[i];
            r *= -1;
            if (r <= mx_r) {
                out << j + 1 << " " << ind + 1 << "\n";
                return;
            } else {
                mx_r = r;
                ind = j;
            }
        }
        
        out << "-1 -1\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskC solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
