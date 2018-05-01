#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

class gcj_1b_c {
private:
    bool make(int u, i64 num, vector<int> &G, const vector<pair<int, int>> &R,
            vector<int> &vis)
    {
        if (G[u] >= num) {
            G[u] -= num;
            return true;
        }
        if (vis[u]) {
            return false;
        }
        vis[u] = 1;
        num -= G[u];
        G[u] = 0;
        int lc = R[u].first, rc = R[u].second;
        if (make(lc, num, G, R, vis) && make(rc, num, G, R, vis)) {
            vis[u] = 0;
            return true;
        }
        vis[u] = 0;
        return false;
    }
public:
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        for (int t = 1; t <= T; ++t) {
            int M;
            in >> M;
            vector<pair<int, int>> R(M);
            for (int i = 0; i < M; ++i) {
                in >> R[i].first >> R[i].second;
                --R[i].first;
                --R[i].second;
            }
            i64 sum = 0;
            vector<int> G(M);
            for (int i = 0; i < M; ++i) {
                in >> G[i];
                sum += G[i];
            }
            i64 low = 0, high = sum, ans = low;
            while (low <= high) {
                vector<int> gg(G), vis(M, 0);
                i64 mid = (low + high) / 2;
                if (make(0, mid, gg, R, vis)) {
                    ans = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            out << "Case #" << t << ": " << ans << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    gcj_1b_c solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
