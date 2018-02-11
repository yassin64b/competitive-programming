#include <bits/stdc++.h>

using namespace std;

class dmoj_val_s4 {
private:
    constexpr static int MOD = 1'000'000'007;
    void dfs(int u, const vector<vector<int>>& g, int &res, const vector<int> &fac) {
        int num = g[u].size() + 1;
        res = (1LL * res * fac[num]) % MOD;
        for (int v : g[u]) {
            dfs(v, g, res, fac);
        }
    }
public:
    void solve(istream& in, ostream& out) {
        int N;
        in >> N;
        vector<vector<int>> g(N);
        for (int i = 0; i < N - 1; ++i) {
            int p;
            in >> p;
            g[p].push_back(i + 1);
        }
        vector<int> fac(N + 1, 0);
        fac[0] = 1;
        for (int i = 1; i <= N; ++i) {
            fac[i] = (1LL * i * fac[i - 1]) % MOD;
        }
        int res = 1;
        dfs(0, g, res, fac);
        out << res << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    dmoj_val_s4 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
