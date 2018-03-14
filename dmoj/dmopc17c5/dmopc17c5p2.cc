#include <bits/stdc++.h>

using namespace std;

class dmopc17c5p2 {
public:
    void solve(istream& in, ostream& out) {
        string S;
        int Q;
        in >> S >> Q;
        int n = S.size();
        vector<int> pre0(n + 1, 0), pre1(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pre0[i + 1] = pre0[i] + (S[i] == '0');
            pre1[i + 1] = pre1[i] + (S[i] == '1');
        }
        for (int q = 0; q < Q; ++q) {
            int x, y, z;
            in >> x >> y >> z;
            --x;
            vector<int> &pre = (z == 0 ? pre0 : pre1);
            int add = pre[x];
            if (pre[n] < y + add) {
                out << -1 << "\n";
                continue;
            }
            int low = x + 1, high = n, ans = high;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (pre[mid] < y + add) {
                    low = mid + 1;
                } else {
                    ans = mid;
                    high = mid - 1;
                }
            }
            out << ans << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    dmopc17c5p2 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
