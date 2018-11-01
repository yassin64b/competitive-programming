#include <bits/stdc++.h>

using namespace std;

class D451 {
public:
    void solve(istream& in, ostream& out) {
        string s;
        in >> s;
        int n = s.size();
        vector<vector<vector<int>>> cnt(2, vector<vector<int>>(2, vector<int>(n + 1, 0)));
        for (int i = n - 1; i >= 0; --i) {
            int id = s[i] - 'a';
            cnt[id][i % 2][i] += 1;
            for (int j = 0; j <= 1; ++j) {
                for (int k = 0; k <= 1; ++k) {
                    cnt[j][k][i] += cnt[j][k][i + 1];
                }
            }
        }
        vector<long long> res(2, 0);
        for (int i = 0; i < n; ++i) {
            int id = s[i] - 'a';
            res[1] += 1;
            bool even = (i % 2 == 0);
            res[even] += cnt[id][0][i + 1];
            res[!even] += cnt[id][1][i + 1];
        }
        out << res[0] << " " << res[1] << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    D451 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
