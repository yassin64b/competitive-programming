#include <bits/stdc++.h>

using namespace std;

class TaskD {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        constexpr int MX = 1'435'243 + 1;
        vector<vector<int>> divs(MX + 1);
        vector<bool> prime(MX + 1, true);
        for (int i = 2; i <= MX; ++i) {
            if (prime[i]) {
                for (int j = i; j <= MX; j += i) {
                    divs[j].push_back(i);
                    prime[j] = false;
                }
            }
        }
        set<int> ok;
        for (int i = 2; i <= MX; ++i) {
            ok.insert(i);
        }
        vector<int> b(n);
        vector<bool> erased(MX + 1, 0);
        bool greater = false;
        for (int i = 0; i < n; ++i) {
            set<int>::iterator it;
            if (greater) {
                it = ok.begin();
            } else {
                it = ok.lower_bound(a[i]);
                if (*it > a[i]) {
                    greater = true;
                }
            }
            b[i] = *it;
            for (int d : divs[b[i]]) {
                for (int x = d; x <= MX; x += d) {
                    if (!erased[x]) {
                        ok.erase(x);
                        erased[x] = 1;
                    }
                }
            }
        }
        for (int x : b) {
            out << x << " ";
        }
        out << "\n";
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
