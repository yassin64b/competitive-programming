#include <bits/stdc++.h>

using namespace std;

constexpr double EPS = 1e-9;

class kickstart_lucky_dip {
public:
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        for (int t = 1; t <= T; ++t) {
            int N, K;
            in >> N >> K;
            vector<double> v(N);
            for (int i = 0; i < N; ++i) {
                in >> v[i];
            }
            sort(begin(v), end(v));
            vector<double> pre_sum(N + 1, 0.);
            for (int i = 1; i <= N; ++i) {
                pre_sum[i] = pre_sum[i - 1] + v[i - 1];
            }
            vector<double> E(K + 2, 0.);
            for (int j = 1, ind = 0; j <= K + 1; ++j) {
                double sum = 0;
                /*for (int i = 0; i < N; ++i) { // O(NK) overall
                    sum += max(v[i], E[j - 1]);
                }*/
                /*auto it = lower_bound(begin(v), end(v), E[j - 1]); // O((N+K)logN) overall
                int ind = it - begin(v);*/
                while (ind < N && v[ind] <= E[j - 1]) { // O(NlogN+K) overall
                    ++ind;
                }
                sum = pre_sum[N] - pre_sum[ind] + ind * E[j - 1];
                E[j] = sum / N;
            }
            
            out << fixed << "Case #" << t << ": " << E[K + 1] << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    kickstart_lucky_dip solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
