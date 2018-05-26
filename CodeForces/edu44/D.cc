#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

class TaskD {
public:
    void solve(istream& in, ostream& out) {
        i64 n, H;
        in >> n >> H;
        i64 low = 1, high = min(n, 2'000'000'000LL);
        i64 last = n;
        while (low <= high) {
            i64 mid = (low + high) / 2;
            i64 res = 0, sum;
            if (mid <= H) {
                sum = mid * (mid + 1) / 2;
                res += mid;
                if (sum < n) {
                    ++res;
                }
            } else {
                sum = mid * (mid + 1) / 2;
                sum += (mid - 1) * (mid) / 2;
                sum -= (H - 1) * (H) / 2;
                res += mid + mid - 1 - (H - 1);
                if (sum < n) {
                    ++res;
                }
            }
            if (sum <= n) {
                low = mid + 1;
                if (sum + mid >= n) {
                    last = min(res, last);
                } else {
                    i64 rest = n - sum - 1;
                    last = min(res + rest / mid, last);
                }
            } else {
                high = mid - 1;
            }
        }
        out << last << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskD solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
