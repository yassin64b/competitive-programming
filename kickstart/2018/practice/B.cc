#include <bits/stdc++.h>

using namespace std;

class kickstart_b {
private:
    int solve(long long K, const vector<long long> &len, int i) {
        assert(i >= 0);
        assert(len[i] % 2 == 1);
        long long mid = len[i] / 2;
        if (K == mid) {
            // K is exactly on the mid of S_i, thus it must be 0
            return 0;
        } else if (K < mid) {
            // K is in left half --> just continue on left half
            int res = solve(K, len, i - 1);
            return res;
        } else {
            // K is in the right half --> reverse and switch
            long long dist = K - mid;
            long long new_K = mid - dist; // calc reverse position in left half
            int res = solve(new_K, len, i - 1);
            return 1 - res; // switch
        }
    }
public:
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        vector<long long> len{0};
        while (len.back() < 2e18) {
            len.push_back(len.back() * 2 + 1);
        }
        for (int t = 1; t <= T; ++t) {
            long long K;
            in >> K;
            out << "Case #" << t << ": " << solve(--K, len, (int)len.size() - 1) << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    kickstart_b solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
