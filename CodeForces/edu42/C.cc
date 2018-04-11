#include <bits/stdc++.h>

using namespace std;

class TaskC {
private:
    int change(int n, int m) {
        // also works, but slower
        /*string sn(to_string(n)), sm(to_string(m));
        for (int j = 0, i = 0; j < (int)sm.size(); ++j, ++i) {
            while (i < (int)sn.size() && sn[i] != sm[j]) {
                ++i;
            }
            if (i == (int)sn.size()) {
                return -1;
            }
        }
        return (int)sn.size() - (int)sm.size();*/
        
        int res = 0;
        while (n) {
            if (n % 10 == m % 10 && m) {
                n /= 10;
                m /= 10;
            } else {
                n /= 10;
                ++res;
            }
        }
        if (m) {
            return -1;
        }
        return res;
    }
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        int res = -1;
        for (int x = 1; x * x <= n; ++x) {
            int m = x * x;
            int cur = change(n, m);
            if (cur != -1) {
                if (res == -1) {
                    res = cur;
                }
                res = min(res, cur);
            }
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
