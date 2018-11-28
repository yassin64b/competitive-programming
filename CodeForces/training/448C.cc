#include <bits/stdc++.h>

using namespace std;

class C448 {
private:
    int solve(const vector<int> &a, int l, int r, int sub) {
        if (l > r) {
            return 0;
        }
        int ind = min_element(begin(a) + l, begin(a) + r + 1) - begin(a);
        int mn = a[ind];
        // either paint whole subarray vertical
        // or paint horizontal up to the minimum value
        // (never optimal to first paint some minimum elements vertical and then sth horizontal
        // because horizontal coloring could be extended without cost to cover these min elements)
        return min(r - l + 1, solve(a, l, ind - 1, mn) + solve(a, ind + 1, r, mn) + mn - sub);
    }
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        out << solve(a, 0, n - 1, 0) << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    C448 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
