#include <bits/stdc++.h>

using namespace std;

class TaskC {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        vector<vector<int>> divs(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j * j <= a[i] && j <= n; ++j) {
                if (a[i] % j == 0) {
                    divs[i].push_back(j);
                    int tmp = a[i] / j;
                    if (tmp <= n && tmp != j) {
                        divs[i].push_back(tmp);
                    }
                }
            }
            sort(begin(divs[i]), end(divs[i]));
            reverse(begin(divs[i]), end(divs[i]));
        }
        constexpr int MOD = 1'000'000'007;
        vector<int> num(n + 1, 0);
        num[0] = 1;
        for (int i = 0; i < n; ++i) {
            /*vector<int> nxt(num);
            for (int j = 1; j * j <= a[i] && j <= n; ++j) {
                if (a[i] % j == 0) {
                    nxt[j] = (nxt[j] + num[j - 1]) % MOD;
                    int tmp = a[i] / j;
                    if (tmp <= n && tmp != j) {
                        nxt[tmp] = (nxt[tmp] + num[tmp - 1]) % MOD;
                    }
                }
            }
            num = nxt;*/
            for (int j : divs[i]) {
                if (a[i] % j == 0) {
                    num[j] = (num[j] + num[j - 1]) % MOD;
                }
            }
        }
        out << (accumulate(begin(num), end(num), 0LL) - 1 + MOD) % MOD << "\n";
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
