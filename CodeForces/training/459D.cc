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
    FenwickTree(int n_) : n(n_) {
        ft.assign(n_ + 1, 0);
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
    //NOTE: when using range update, rsq(x) is point query + don't use update(a, v)!!
    void update(int a, int b, int v) {
        update(a, v);
        update(b + 1, -v);
    }
    int upper_bound(int s) {
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

class D459 {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        map<int, int> m;
        for (int i = 0, id = 0; i < n; ++i) {
            if (m.count(a[i])) {
                a[i] = m[a[i]];
            } else {
                a[i] = m[a[i]] = id++;
            }
        }
        FenwickTree ft(n);
        //map<int, int> cnt1, cnt2;
        vector<int> cnt1(n, 0), cnt2(n, 0);
        for (int i = 0; i < n; ++i) {
            ++cnt1[a[i]];
        }
        long long res = 0;
        for (int i = n - 1; i >= 0; --i) {
            int v = cnt1[a[i]];
            res += ft.rsq(1, v - 1);
            --cnt1[a[i]];
            ++cnt2[a[i]];
            ft.update(cnt2[a[i]], 1);
        }
        out << res << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    D459 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
