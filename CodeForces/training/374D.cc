#include <bits/stdc++.h>

using namespace std;

int hibit(unsigned int n) {
    n |= (n >>  1);
    n |= (n >>  2);
    n |= (n >>  4);
    n |= (n >>  8);
    n |= (n >> 16);
    return n - (n >> 1);
}

class FenwickTree {
private:
    vector<int> ft;
    int n, msb;
public:
    FenwickTree(int n) : n(n) {
        ft.assign(n + 1, 0);
        msb = hibit(n);
    }
    int rsq(int b) {
        int sum = 0;
        for (; b; b -= (b & (-b))) {
            sum += ft[b];
        }
        return sum;
    }
    int rsq(int a, int b) {
        if (a > b) return 0;
        return rsq(b) - rsq(a - 1);
    }
    void update(int a, int v) {
        for ( ; a < (int)ft.size(); a += (a & (-a))) {
            ft[a] += v;
        }
    }
    int lower_bound(int s) {
        int pos = 0;
        for (int bs = msb; bs > 0; bs /= 2) {
            int nxt = bs + pos;
            if (nxt <= n && s >= ft[nxt]) {
                s -= ft[nxt];
                pos = nxt;
            }
        }
        if (s) {
            return -1;
        } else {
            return pos + 1;
        }
    }
};

class D374 {
public:
    void solve(istream& in, ostream& out) {
        int n, m;
        in >> n >> m;
        vector<int> a(m);
        for (int i = 0; i < m; ++i) {
            in >> a[i];
        }
        FenwickTree ft(n);
        vector<int> events(n), v;
        for (int i = 0, ind = 0; i < n; ++i) {
            in >> events[i];
            if (events[i] == -1) {
                for (int j = 0; j < m; ++j) {
                    int pos = ft.lower_bound(a[j] - j - 1);
                    if (pos <= 0 || pos > n) {
                        break;
                    }
                    ft.update(pos, -1);
                }
            } else {
                ft.update(++ind, 1);
                v.push_back(events[i]);
            }
        }
        string res;
        for (int i = 0; i < (int)v.size(); ++i) {
            if (ft.rsq(i + 1, i + 1) == 1) {
                res += v[i] + '0';
            }
        }
        out << (res.empty() ? "Poor stack!" : res) << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    D374 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
