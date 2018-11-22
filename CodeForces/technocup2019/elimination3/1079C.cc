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
        vector<vector<int>> dp(n, vector<int>(5, 0));
        for (int j = 0; j < 5; ++j) {
            dp[0][j] = 1;
        }
        for (int i = 0; i + 1 < n; ++i) {
            for (int j = 0; j < 5; ++j) {
                if (dp[i][j]) {
                    if (a[i] < a[i + 1]) {
                        for (int k = j + 1; k < 5; ++k) dp[i + 1][k] = 1;
                    } else if (a[i] > a[i + 1]) {
                        for (int k = 0; k < j; ++k) dp[i + 1][k] = 1;
                    } else if (a[i] == a[i + 1]) {
                        for (int k = 0; k < 5; ++k) if (k != j) dp[i + 1][k] = 1;
                    }
                }
            }
        }
        int b = -1;
        for (int j = 0; j < 5; ++j) {
            if (dp[n - 1][j]) {
                b = j;
            }
        }
        if (b == -1) {
            out << -1 << "\n";
            return;
        }
        vector<int> res{b};
        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j < 5; ++j) {
                if (dp[i][j]) {
                    if (a[i] < a[i + 1]) {
                        for (int k = j + 1; k < 5; ++k) if (k == b) {
                                b = j;
                                goto end;
                            }
                    } else if (a[i] > a[i + 1]) {
                        for (int k = 0; k < j; ++k) if (k == b) {
                                b = j;
                                goto end;
                            }
                    } else if (a[i] == a[i + 1]) {
                        for (int k = 0; k < 5; ++k) if (k != j && k == b) {
                            b = j;
                            goto end;
                        }
                    }
                }
            }
            end:
            res.push_back(b);
        }
        reverse(begin(res), end(res));
        for (int x : res) {
            out << x + 1 << " ";
        }
        out << "\n";
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
