#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

class dwacon5_b {
public:
    void solve(istream& in, ostream& out) {
        int N, K;
        in >> N >> K;
        vector<int> a(N);
        for (int i = 0; i < N; ++i) {
            in >> a[i];
        }
        vector<i64> vals;
        for (int i = 0; i < N; ++i) {
            i64 beauty = 0;
            for (int j = i; j < N; ++j) {
                beauty += a[j];
                vals.push_back(beauty);
            }
        }
        i64 res = 0;
        for (int shift = 60; shift >= 0; --shift) {
            int cnt = 0;
            i64 mask = (1LL << shift);
            for (i64 x : vals) {
                if (x & mask) {
                    ++cnt;
                }
            }
            if (cnt >= K) {
                res |= mask;
                vector<i64> newvals;
                for (i64 x : vals) {
                    if (x & mask) {
                        newvals.push_back(x);
                    }
                }
                vals = newvals;
            }
        }
        out << res << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    dwacon5_b solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
