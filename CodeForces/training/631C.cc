#include <bits/stdc++.h>

using namespace std;

class C631 {
public:
    void solve(istream& in, ostream& out) {
        int n, m;
        in >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        vector<int> t(m), r(m);
        for (int i = 0; i < m; ++i) {
            in >> t[i] >> r[i];
        }
        vector<int> sufr(m + 1);
        sufr[m] = 0;
        for (int i = m - 1; i >= 0; --i) {
            sufr[i] = max(sufr[i + 1], r[i]);
        }
        sort(begin(a), begin(a) + sufr[0]);
        vector<int> res(n);
        for (int i = sufr[0]; i < n; ++i) {
            res[i] = a[i];
        }
        for (int i = 0, ni = 0, nj = sufr[0] - 1; i < m; ++i) {
            int from = sufr[i + 1], to = r[i];
            if (t[i] == 1) { // sort increasing -> fill [from, to) with maximums of [0, to)
                for (int j = to - 1; j >= from; --j, --nj) {
                    res[j] = a[nj];
                }
            } else { // sort decreasing -> fill [from, to) with minimums of [0, to)
                for (int j = to - 1; j >= from; --j, ++ni) {
                    res[j] = a[ni];
                }
            }
        }
        for (int x : res) {
            out << x << " ";
        }
        out << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    C631 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
