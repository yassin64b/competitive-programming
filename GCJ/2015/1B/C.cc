#include <bits/stdc++.h>

using namespace std;

constexpr double EPS = 1e-9;

class gcj_hiking_deer {
public:
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        for (int t = 1; t <= T; ++t) {
            int N;
            in >> N;
            vector<int> D(N), H(N), M(N);
            for (int i = 0; i < N; ++i) {
                in >> D[i] >> H[i] >> M[i];
            }
            priority_queue<pair<double, int>> pq;
            vector<double> speed;
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < H[i]; ++j) {
                    speed.push_back(M[i] + j);
                    pq.emplace(-(360. - D[i]) / 360. * speed.back(), (int)speed.size() - 1);
                }
            }
            int m = speed.size(), cur = m, j = 0, best = m;
            vector<int> vis(m, 0);
            while (!pq.empty() && ++j <= 2 * m) {
                double cur_t = -pq.top().first;
                int i = pq.top().second;
                pq.pop();
                if (!vis[i]) {
                    --cur;
                    vis[i] = 1;
                    // use EPS so that adds will get handled earlier than subtracts
                    cur_t -= EPS;
                } else {
                    ++cur;
                }
                pq.emplace(-(cur_t + speed[i] - EPS), i); 
                best = min(best, cur);
            }
            out << "Case #" << t << ": " << best << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    gcj_hiking_deer solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
