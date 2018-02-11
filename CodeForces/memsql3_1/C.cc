#include <bits/stdc++.h>

using namespace std;

class TaskC {
private:
    pair<int, int> dfs(int i, const vector<int> &slice, vector<pair<int, int>> &dp) {
        int N = slice.size();
        if (i >= N) {
            return {0, 0};
        } else if (dp[i] != make_pair(-1, -1)) {
            return dp[i];
        }
        pair<int, int> res{0, 0}, cur{0, 0};
        for (int j = i; j < N; ++j) {
            pair<int, int> tmp = dfs(j + 1, slice, dp);
            res = max(res, {slice[j] + tmp.second, cur.second + tmp.first});
            cur.second += slice[j];
        }
        return dp[i] = res;
    }
public:
    void solve(istream& in, ostream& out) {
        int N;
        in >> N;
        vector<int> slice(N);
        for (int i = 0; i < N; ++i) {
            in >> slice[i];
        }
        vector<pair<int, int>> dp(N, {-1, -1});
        pair<int, int> res = dfs(0, slice, dp);
        out << res.second << " " << res.first << "\n";
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
