#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

class gcj_bathroom_stalls {
public:
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        for (int t = 1; t <= T; ++t) {
            i64 N, K;
            in >> N >> K;
            priority_queue<i64> pq;
            map<i64, i64> m;
            pq.emplace(N);
            m[N] = 1;
            while (true) {
                i64 len = pq.top();
                pq.pop();
                K -= m[len];
                i64 a = (len - 1) / 2, b = len / 2;
                if (K <= 0) {
                    out << "Case #" << t << ": " << b << " " << a << "\n";
                    break;
                }
                if (!m.count(a)) {
                    pq.emplace(a);
                }
                m[a] += m[len];
                if (!m.count(b)) {
                    pq.emplace(b);
                }
                m[b] += m[len];
                m.erase(len);
            }
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    gcj_bathroom_stalls solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
