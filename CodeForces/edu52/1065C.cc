#include <bits/stdc++.h>

using namespace std;

class TaskC {
public:
    void solve(istream& in, ostream& out) {
        int n, k;
        in >> n >> k;
        vector<int> h(n), v(200'001, 0);
        for (int i = 0; i < n; ++i) {
            in >> h[i];
            v[h[i]] += 1;
        }
        int to = *min_element(begin(h), end(h));
        int cnt = 0, res = 0;
        long long cur = 0;
        for (int i = 200'000; i > to; --i) {
            long long add = cnt + v[i];
            if (add + cur > k) {
                ++res;
                cur = add;
            } else {
                cur += add;
            }
            cnt += v[i];
        }
        out << res + (cur > 0) << "\n";
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
