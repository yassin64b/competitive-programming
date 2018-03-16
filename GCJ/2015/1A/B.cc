#include <bits/stdc++.h>

using namespace std;

class gcj_haircut {
private:
    long long count_served(long long T, const vector<int> &M) {
        if (T < 0) {
            return 0;
        }
        long long cnt = 0;
        for (int i = 0; i < (int)M.size(); ++i) {
            long long num = (T + M[i]) / M[i];
            cnt += num;
        }
        return cnt;
    }
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
            while (low <= high) {
                long long mid = (low + high) / 2;
                long long cnt_served = count_served(mid, M);
                if (cnt_served >= N) {
                    ans = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            int cnt_served_bef = count_served(ans - 1, M);
            int res = 0, diff = N - cnt_served_bef;
            for (int i = 0; i < B; ++i) {
                if (ans % M[i] == 0 && --diff == 0) {
                    res = i + 1;
                }
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
