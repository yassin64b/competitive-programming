#include <bits/stdc++.h>

using namespace std;

class TaskC {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> a(n);
        constexpr int MX = 100'000;
        vector<int> cnt(MX + 1, 0);
        int num = 0;
        for (int i = 0; i < n; ++i) {
            in >> a[i];
            if (++cnt[a[i]] == 1) {
                ++num;
            }
        }
        long long res = 0;
        vector<int> vis(MX + 1, 0);
        for (int i = 0; i < n; ++i) {
            if (--cnt[a[i]] == 0) {
                --num;
            }
            if (vis[a[i]]) {
                continue;
            }
            vis[a[i]] = 1;
            res += num;
        }
        out << res << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskC solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
