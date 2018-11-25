#include <bits/stdc++.h>

using namespace std;

class TaskB {
public:
    void solve(istream& in, ostream& out) {
        long long n, m;
        in >> n >> m;
        vector<long long> cnt(m, 0);
        for (int i = 1; i <= m; ++i) {
            cnt[i * i % m] += n / m;
        }
        for (int i = 1; i <= n % m; ++i) {
            cnt[i * i % m] += 1;
        }
        long long res = 0;
        for (int i = 1; i <= m; ++i) {
            int rest = (m - (i * i) % m);
            if (rest == m) rest = 0;
            res += cnt[rest] * (n / m);
        }
        for (int i = 1; i <= n % m; ++i) {
            int rest = (m - (i * i) % m);
            if (rest == m) rest = 0;
            res += cnt[rest];
        }
        out << res << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskB solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
