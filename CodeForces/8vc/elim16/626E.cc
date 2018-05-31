#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

class TaskE {
private:
    double get(int i, int len, const vector<i64> &x, const vector<i64> &pre) {
        int n = x.size();
        i64 sum = x[i] + pre[n - 1] - pre[n - 1 - len] + pre[i - 1];
        if (i - 1 - len >= 0) sum -= pre[i - 1 - len];
        return (double)sum / (2 * len + 1);
    }
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<i64> x(n);
        for (int i = 0; i < n; ++i) {
            in >> x[i];
        }
        if (n <= 2) {
            out << 1 << "\n" << x[0] << "\n";
            return;
        }
        sort(begin(x), end(x));
        vector<i64> pre(x);
        for (int i = 1; i < n; ++i) {
            pre[i] += pre[i - 1];
        }
        double res = 0;
        int ind = 0, len = 0;
        for (int i = 1; i < n - 1; ++i) {
            int low = 1, high = min(i, n - 1 - i), ans = low;
            while (low <= high) {
                int mid = (low + high) / 2;
                double a = get(i, mid, x, pre);
                double b = get(i, mid - 1, x, pre);
                if (a >= b) {
                    low = mid + 1;
                    ans = mid;
                } else {
                    high = mid - 1;
                }
            }
            double cur = get(i, ans, x, pre) - x[i];
            if (cur > res) {
                res = cur;
                ind = i;
                len = ans;
            }
        }
        vector<int> subset;
        for (int i = ind - len; i <= ind; ++i) {
            subset.push_back(x[i]);
        }
        for (int i = n - len; i < n; ++i) {
            subset.push_back(x[i]);
        }
        out << 2 * len + 1 << "\n";
        for (int z : subset) {
            out << z << " ";
        }
        out << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskE solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
