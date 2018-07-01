#include <bits/stdc++.h>

using namespace std;

struct Query {
    int L, R, i;
};
class TaskF {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        int sqrt_n = sqrt(n) + 1;
        int q;
        in >> q;
        vector<Query> v(q);
        for (int i = 0; i < q; ++i) {
            in >> v[i].L >> v[i].R;
            --v[i].L;
            --v[i].R;
            v[i].i = i;
        }
        sort(begin(v), end(v), [sqrt_n](const Query &lhs, const Query &rhs) {
            if (lhs.L / sqrt_n == rhs.L / sqrt_n) {
                int sign = (lhs.L / sqrt_n % 2 == 1 ? 1 : -1);
                return sign * lhs.R < sign * rhs.R;
            }
            return lhs.L / sqrt_n < rhs.L / sqrt_n;
        });
        int res[5 * 100'000 + 1]{};
        int cnt[5 * 100'000 + 1]{};
        int block_cnt[5 * 100'000 + 1]{};
        int total_cnt = 0;
        int curL = 0, curR = 0;
        auto add = [&total_cnt, &block_cnt, sqrt_n, &cnt, &a](int i) {
            if (++cnt[a[i]] == 1) {
                ++total_cnt;
                ++block_cnt[a[i] / sqrt_n];
            } else if (cnt[a[i]] == 2) {
                --total_cnt;
                --block_cnt[a[i] / sqrt_n];
            }
        };
        auto remove = [&total_cnt, &block_cnt, sqrt_n, &cnt, &a](int i) {
            if (--cnt[a[i]] == 0) {
                --total_cnt;
                --block_cnt[a[i] / sqrt_n];
            } else if (cnt[a[i]] == 1) {
                ++total_cnt;
                ++block_cnt[a[i] / sqrt_n];
            }
        };
        auto get_res = [&total_cnt, &block_cnt, sqrt_n, &cnt]() {
            if (total_cnt == 0) {
                return 0;
            }
            for (int i = 0; i < sqrt_n; ++i) {
                if (block_cnt[i]) {
                    for (int j = i * sqrt_n; ; ++j) {
                        if (cnt[j] == 1) {
                            return j;
                        }
                    }
                }
            }
        };
        for (int i = 0; i < q; ++i) {
            int L = v[i].L, R = v[i].R;
            while (curL < L) {
                remove(curL++);
            }
            while (curL > L) {
                add(--curL);
            }
            while (curR <= R) {
                add(curR++);
            }
            while (curR > R + 1) {
                remove(--curR);
            }
            res[v[i].i] = get_res();
        }
        for (int i = 0; i < q; ++i) {
            out << res[i] << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskF solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
