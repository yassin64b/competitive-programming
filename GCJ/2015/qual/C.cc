#include <bits/stdc++.h>

using namespace std;

struct a {
    enum s_char { // 0 = one, 1 = i, 2 = j, 3 = k
        one, i, j, k
    };
};

class gcj_dijkstra {
private:
    const int _mult[5][5] = {{0, 0, 0, 0, 0}, 
                            {0, 1, 2, 3, 4},
                            {0, 2, -1, 4, -3},
                            {0, 3, -4, -1, 2},
                            {0, 4, 3, -2, -1}};
    int mult(int x, int y) {
        int sign = ((x * y > 0) ? 1 : -1);
        return sign * _mult[abs(x)][abs(y)];
    }
    int mult_all(const string &s, int L, long long X) {
        int res = 1;
        /*for (int i = 0; i < X; ++i) {
            for (int j = 0; j < L; ++j) {
                res = mult(res, s[j]);
            }
        }*/
        for (int j = 0; j < L; ++j) {
            res = mult(res, s[j]);
        }
        res = fast_pow(res, X);
        return res;
    }
    int fast_pow(int x, long long y) {
        if (y == 0) {
            return 1; 
        } else if (y % 2 == 1) {
            return mult(fast_pow(x, y - 1), x);
        } else {
            int tmp = fast_pow(x, y / 2);
            return mult(tmp, tmp);
        }
    }
    bool check_pre(const string &s, int L, long long X) {
        int pre1 = 1, pre2 = 1;
        for (int i = 0; i < X; ++i) {
            for (int j = 0; j < L; ++j) {
                if (pre1 != 2) {
                    pre1 = mult(pre1, s[j]);
                } else if (pre2 != 3) {
                    pre2 = mult(pre2, s[j]);
                }
            }
        }
        return pre1 == 2 && pre2 == 3;
    } 
public:
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        for (int t = 1; t <= T; ++t) {
            long long L, X;
            string s;
            in >> L >> X >> s;
            for (char &c : s) {
                c = c - 'i' + 2;
            }
            bool ok = (mult_all(s, L, X) == -1 && check_pre(s, L, min(X, 100LL)));
            out << "Case #" << t << ": " << (ok ? "YES\n" : "NO\n");
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    gcj_dijkstra solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
