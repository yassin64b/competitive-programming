#include <bits/stdc++.h>

using namespace std;

class TaskC {
public:
    void solve(istream& in, ostream& out) {
        int n, m;
        in >> n >> m;
        vector<int> vert(n);
        for (int i = 0; i < n; ++i) {
            in >> vert[i];
        }
        vector<tuple<int, int, int>> hor(m);
        vector<int> realhor;
        for (int i = 0; i < m; ++i) {
            int x1, x2, y;
            in >> x1 >> x2 >> y;
            hor[i] = {x1, x2, y};
            if (x1 == 1) {
                realhor.push_back(x2);
            }
        }
        vert.push_back(1'000'000'000); // case: after removing all vert
        int k = realhor.size();
        sort(begin(realhor), end(realhor));
        sort(begin(vert), end(vert));
        int res = n + m;
        for (int i = 0, j = 0; i <= n; ++i) {
            // before removing vert[i]
            while (j < k && realhor[j] < vert[i]) {
                ++j;
            }
            int horleft = k - j;
            res = min(res, horleft + i);
        }
        out << res << "\n";
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
