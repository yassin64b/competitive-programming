#include <bits/stdc++.h>

using namespace std;

class gcj_1b_a {
public:
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        for (int t = 1; t <= T; ++t) {
            int N, L;
            in >> N >> L;
            vector<int> C(L);
            int cur = 0;
            for (int i = 0; i < L; ++i) {
                in >> C[i];
                cur += C[i];
            }
            set<int> s;
            for (int i = 0; i <= N; ++i) {
                int num = i * 100;
                if (2 * (num % N) >= N) {
                    s.insert(i);
                }
            }
            for (int j = 0; j < N - cur; ++j) {
                C.push_back(0);
            }
            priority_queue<pair<int, int>> pq;
            for (int i = 0; i < (int)C.size(); ++i) {
                if (!s.count(C[i])) {
                    auto it = s.lower_bound(C[i]);
                    if (it != s.end()) {
                        int num = *it;
                        int dist = num - C[i];
                        pq.emplace(-dist, i);
                    }
                }
            }
            for (int j = 0; j < N - cur; ++j) {
                if (pq.empty()) {
                    C.back() += 1;
                    continue;
                }
                int dist = -pq.top().first, ind = pq.top().second;
                pq.pop();
                ++C[ind];
                if (dist - 1 > 0) {
                    pq.emplace(-(dist - 1), ind);
                }
            }
            int res = 0;
            for (int x : C) {
                int num = x * 100;
                res += num / N;
                if (2 * (num % N) >= N) {
                    ++res;
                }
            }
            out << "Case #" << t << ": " << res << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    gcj_1b_a solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
