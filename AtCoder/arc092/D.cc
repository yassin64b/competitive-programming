#include <bits/stdc++.h>

using namespace std;

class arc092_d {
private:
    int count(int start_num, int end_num, const vector<int> &b) {
        auto it_start = lower_bound(begin(b), end(b), start_num);
        auto it_end = lower_bound(begin(b), end(b), end_num);
        int cnt = it_end - it_start;
        return cnt;
    }
public:
    void solve(istream& in, ostream& out) {
        int N;
        in >> N;
        vector<int> a(N), b(N);
        for (int i = 0; i < N; ++i) {
            in >> a[i];
        }
        for (int i = 0; i < N; ++i) {
            in >> b[i];
        }
        vector<int> res(29, 0);
        for (int j = 0; j < 29; ++j) {
            int T = (1 << j);
            vector<int> cur_a(N), cur_b(N);
            for (int i = 0; i < N; ++i) {
                cur_a[i] = a[i] % (2 * T);
                cur_b[i] = b[i] % (2 * T);
            }
            sort(begin(cur_b), end(cur_b));
            for (int i = 0; i < N; ++i) {
                res[j] += count(T - cur_a[i], 2 * T - cur_a[i], cur_b);
                res[j] += count(3 * T - cur_a[i], 4 * T - cur_a[i], cur_b);
            }
        }
        int ans = 0;
        for (int j = 0; j < 29; ++j) {
            if (res[j] % 2) {
                ans |= (1 << j);
            }
        }
        out << ans << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    arc092_d solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
