#include <bits/stdc++.h>

using namespace std;

class gcj_haircut {
public:
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        for (int t = 1; t <= T; ++t) {
            int B, N;
            in >> B >> N;
            vector<int> M(B);
            for (int i = 0; i < B; ++i) {
                in >> M[i];
            }

            constexpr int MXM = 100000;
            long long low = 0, high = 1LL * MXM * N, ans = high;
            while (low <= high) { // find lowest time such that over N served
                long long mid = (low + high) / 2;
                vector<long long> end_t(B, 0);
                long long sum = 0;
                for (int i = 0; i < B; ++i) {
                    long long num = mid / M[i];
                    end_t[i] = num * M[i];
                    sum += num;
                }
                if (sum > N) {
                    ans = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            
            long long latest_start = 0; // find latest starting job
            for (int i = 0; i < B; ++i) {
                long long num = ans / M[i];
                latest_start = max(latest_start, num * M[i] - M[i]);
            }
            vector<long long> end_t(B, 0);
            long long sum = 0;
            priority_queue<pair<int, int>> pq;
            for (int i = 0; i < B; ++i) { // count no. of jobs done
                long long num = (latest_start + M[i]) / M[i];
                end_t[i] = num * M[i];
                pq.emplace(end_t[i] - M[i], i); // insert last job starting time
                sum += num;
            }
            int res = 0;
            for (; sum >= N; --sum) { // while too many jobs, remove largest starting time
                auto p = pq.top();
                pq.pop();
                int ind = p.second;
                long long val = p.first;
                val -= M[ind];
                res = ind + 1;
                pq.emplace(val, ind);
            }
            
            out << "Case #" << t << ": " << res << "\n";
            out.flush();
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    gcj_haircut solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
