#include <bits/stdc++.h>

using namespace std;

class TaskC {
private:
    void lis(const vector<int> &a, vector<int> &res) {
        int n = a.size();
        vector<int> lis;
        lis.push_back(a[0]);
        res[0] = 1;
        for (int i = 1; i < n; ++i) {
            if (a[i] >= lis.back()) {
                lis.push_back(a[i]);
            } else {
                auto it = upper_bound(lis.begin(), lis.end(), a[i]);
                *it = a[i];
            }
            res[i] = lis.size();
        }
    }
    // alternative to reverse b, lis b, reverse res
    void lds(const vector<int> &a, vector<int> &res) {
        int n = a.size();
        vector<int> lds;
        lds.push_back(a[n - 1]);
        res[n - 1] = 1;
        for (int i = n - 2; i >= 0; --i) {
            if (a[i] >= lds.back()) {
                lds.push_back(a[i]);
            } else {
                auto it = upper_bound(lds.begin(), lds.end(), a[i]);
                *it = a[i];
            }
            res[i] = lds.size();
        }
    }
public:
    void solve(istream& in, ostream& out) {
        int n, m;
        in >> n >> m;
        vector<pair<int, int>> lr(n);
        vector<int> a(m + 1, 0);
        for (int i = 0; i < n; ++i) {
            in >> lr[i].first >> lr[i].second;
            --lr[i].first;
            --lr[i].second;
            ++a[lr[i].first];
            --a[lr[i].second + 1];
        }
        for (int i = 1; i <= m; ++i) {
            a[i] += a[i - 1];
        }
        a.pop_back();
        vector<int> b(a);
        vector<int> ra(m, 0), rb(m, 0);
        // compute ra[i] = lis ending in i
        lis(a, ra);
        // compute rb[i] = lds beginning in i
        reverse(begin(b), end(b));
        lis(b, rb);
        reverse(begin(rb), end(rb));
        int res = max(rb[0], ra[m - 1]);
        for (int i = 1; i < m; ++i) {
            res = max(res, ra[i - 1] + rb[i]);
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
