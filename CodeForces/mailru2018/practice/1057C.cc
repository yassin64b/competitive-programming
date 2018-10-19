#include <bits/stdc++.h>

using namespace std;

class C1057 {
public:
    void solve(istream& in, ostream& out) {
        int n, s, k;
        in >> n >> s >> k;
        --s;
        vector<int> r(n);
        vector<pair<int, int>> ord(n);
        for (int i = 0; i < n; ++i) {
            in >> r[i];
            ord[i] = {r[i], i};
        }
        string col;
        in >> col;
        sort(begin(ord), end(ord));
        
        const int INF = 3'000;
        vector<vector<int>> dp(n, vector<int>(n * n + 1, -INF));
        for (int i = 0; i < n; ++i) {
            int dist = abs(s - i);
            dp[i][dist] = r[i];
        }
        for (int ind = 0; ind < n; ++ind) {
            int i = ord[ind].second;
            for (int j = 0; j < n; ++j) {
                if (r[j] > r[i] && col[j] != col[i]) {
                    int dist = abs(i - j);
                    for (int k = n * n - dist; k >= 0; --k) {
                        dp[j][k + dist] = max(dp[j][k + dist], dp[i][k] + r[j]);
                    }
                }
            }
        }
        int res = 3'000;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n * n; ++j) {
                if (dp[i][j] >= k) {
                    res = min(res, j);
                }
            }
        }
        out << (res == INF ? -1 : res) << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    C1057 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
