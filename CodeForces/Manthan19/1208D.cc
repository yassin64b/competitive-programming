#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

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
    vector<i64> ft;
    int n, msb;
public:
    FenwickTree(int n_) : n(n_) {
        ft.assign(n_ + 1, 0);
        msb = hibit(n);
    }
    i64 rsq(int b) {
        i64 sum = 0;
        for (; b; b -= (b & (-b))) {
            sum += ft[b];
        }
        return sum;
    }
    i64 rsq(int a, int b) {
        if (a > b) return 0;
        return rsq(b) - rsq(a - 1);
    }
    void update(int a, i64 v) {
        for ( ; a < (int)ft.size(); a += (a & (-a))) {
            ft[a] += v;
        }
    }
    int upper_bound(i64 s) {
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

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<i64> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    vector<i64> sum_small(n + 1, 0);
    for (int i = 2; i <= n; ++i) {
        sum_small[i] = sum_small[i - 1] + i - 1;
    }
    map<i64, int> rev;
    for (int i = 1; i <= n; ++i) {
        rev[sum_small[i]] = i;
    }
    vector<int> res(n, 0);
    FenwickTree ft(n);
    for (int i = 1; i <= n; ++i) {
        ft.update(i, i);
    }
    for (int i = n - 1; i >= 0; --i) {
        i64 val = s[i];
        int ind = ft.upper_bound(val);
        res[i] = ind;
        if (ind > 0) ft.update(ind, -ind);
    }
    for (int x : res) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}