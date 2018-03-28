#include <bits/stdc++.h>

using namespace std;

class A570 {
public:
    void solve(istream& in, ostream& out) {
        int n, m;
        in >> n >> m;
        vector<int> city_votes(n, 0);
        for (int i = 0; i < m; ++i) {
            int mxa = -1, ind = -1;
            for (int j = 0; j < n; ++j) {
                int a;
                in >> a;
                if (a > mxa) {
                    mxa = a;
                    ind = j;
                }
            }
            ++city_votes[ind];
        }
        out << max_element(begin(city_votes), end(city_votes)) - begin(city_votes) + 1 << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    A570 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
