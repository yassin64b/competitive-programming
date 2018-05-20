#include <bits/stdc++.h>

using namespace std;

class A388 {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> x(n);
        for (int i = 0; i < n; ++i) {
            in >> x[i];
        }
        sort(begin(x), end(x));
        reverse(begin(x), end(x));
        int low = 1, high = n, ans = high;
        while (low <= high) {
            int mid = (low + high) / 2;
            vector<vector<int>> piles(mid);
            for (int i = 0; i < n; ++i) {
                piles[i % mid].push_back(x[i]);
            }
            bool ok = true;
            for (int i = 0; i < mid; ++i) {
                int m = piles[i].size();
                for (int j = 0; j < m; ++j) {
                    if (m - j - 1 > piles[i][j]) {
                        ok = false;
                    }
                }
            }
            if (ok) {
                high = mid - 1;
                ans = mid;
            } else {
                low = mid + 1;
            }
        }
        out << ans << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    A388 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
