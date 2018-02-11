#include <bits/stdc++.h>

using namespace std;

class dmoj_val_2 {
public:
    void solve(istream& in, ostream& out) {
        int N, M;
        in >> N >> M;
        vector<int> C(N);
        for (int i = 0; i < N; ++i) {
            in >> C[i];
        }
        vector<pair<int, vector<int>>> deal(M, {0, vector<int>(N)});
        for (int i = 0; i < M; ++i) {
            in >> deal[i].first;
            for (int j = 0; j < N; ++j) {
                in >> deal[i].second[j];
            }
        }
        vector<int> need(N);
        for (int i = 0; i < N; ++i) {
            in >> need[i];
        }
        int res = 2'000'000'000;
        for (int set_deals = 0; set_deals <= (1 << M); ++set_deals) {
            int cost = 0;
            vector<int> have(N, 0);
            for (int i = 0; i < M; ++i) {
                if ((set_deals & (1 << i))) {
                    cost += deal[i].first;
                    for (int j = 0; j < N; ++j) {
                        have[j] += deal[i].second[j];
                    }
                }
            }
            bool ok = true;
            for (int i = 0; i < N; ++i) {
                if (have[i] > need[i]) {
                    ok = false;
                } else {
                    int diff = need[i] - have[i];
                    cost += diff * C[i];
                }
            }
            if (ok) {
                res = min(res, cost);
            }
        }
        out << res << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    dmoj_val_2 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
