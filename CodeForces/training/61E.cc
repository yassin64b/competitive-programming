#include <bits/stdc++.h>

using namespace std;

class FenwickTree {
private:
    vector<int> ft;
    int n;
public:
    FenwickTree(int n_) : n(n_) {
        ft.assign(n_ + 1, 0);
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
};

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> b(a);
    sort(begin(b), end(b));
    map<int, int> cval;
    for (int i = 0, cur = 0; i < n; ++i) {
        if (cval.count(b[i]) == 0) {
            cval[b[i]] = ++cur;
        }
    }
    for (int i = 0; i < n; ++i) {
        a[i] = cval[a[i]];
    }

    FenwickTree left(n + 1), right(n + 1);
    for (int i = 0; i < n; ++i) {
        right.update(a[i], 1);
    }

    long long res = 0;
    for (int j = 0; j < n; ++j) {
        right.update(a[j], -1);
        int cnt_i = left.rsq(a[j] + 1, n);
        int cnt_k = right.rsq(1, a[j] - 1);
        res += 1LL * cnt_i * cnt_k;
        left.update(a[j], 1);
    }
    cout << res << "\n";

    return 0;
}