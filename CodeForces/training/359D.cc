#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

class SparseTable {
private:
    vector<int> a_;
    vector<vector<int>> t_;
    int (*f_)(int, int);
public:
    SparseTable(vector<int> a, int (*f)(int, int)) : a_(a), f_(f) {
        int n = a_.size();
        int logn = ceil(log2(n));
        if ((1 << logn) <= n) ++logn;
        t_.assign(n, vector<int>(logn));
        for (int i = 0; i < n; ++i) {
            t_[i][0] = a_[i];
        }
        for (int j = 1; (1 << j) <= n; ++j) {
            for (int i = 0; i + (1 << j) <= n; ++i) {
                int k1 = t_[i][j - 1], k2 = t_[i + (1 << (j - 1))][j - 1];
                t_[i][j] = f_(k1, k2);
            }
        }
    }
    int query(int i, int j) {
        int len = j - i + 1;
        int k = log2(len);
        return f_(t_[i][k], t_[j - (1 << k) + 1][k]);
    }
};

class D359 {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        SparseTable rmq(a, [](int x, int y) { return min(x, y); });
        SparseTable rgcd(a, gcd);
        int low = 1, high = n, ans = low;
        while (low <= high) {
            int mid = (low + high) / 2;
            bool ok = false;
            for (int i = 0; i + mid <= n; ++i) {
                if (rmq.query(i, i + mid - 1) == rgcd.query(i, i + mid - 1)) {
                    ok = true;
                    break;
                }
            }
            if (ok) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        vector<int> res;
        for (int i = 0; i + ans <= n; ++i) {
            if (rmq.query(i, i + ans - 1) == rgcd.query(i, i + ans - 1)) {
                res.push_back(i + 1);
            }
        }
        out << res.size() << " " << ans - 1 << "\n";
        for (int l : res) {
            out << l << " ";
        }
        out << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    D359 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
