#include <bits/stdc++.h>

using namespace std;

class TaskB {
public:
    void solve(istream& in, ostream& out) {
        int n, k;
        in >> n >> k;
        string s, t;
        in >> s >> t;
        long long res = 0, cur = 1;
        for (int i = 0; i < n; ++i) {
            if (cur == 1) {
                cur = t[i] - s[i] + 1;
            } else {
                // for every but smallest and largest string, we can add any char
                cur = (cur - 2) * 2;
                // for the smallest we can add every char c in range [s[i], 'b']
                cur += 'b' - s[i] + 1;
                // for the largest we can add c in ['a', t[i]]
                cur += t[i] - 'a' + 1;
            }
            cur = min(cur, 1'000'000'000'000);
            res += min(cur, (long long)k);
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
