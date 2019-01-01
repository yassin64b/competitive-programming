#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void count_inv(int *a, int n, vector<pair<i64, i64>> &f) {
    int k = (1 << n);
    if (k <= 1) {
        return;
    }
    k /= 2;
    count_inv(a, n - 1, f);
    count_inv(a + k, n - 1, f);
    vector<int> old1(a, a + k), old2(a + k, a + 2 * k);
    int l = 0, i = 0, j = 0;
    i64 cur_inv = 0;
    while (i < k && j < k) {
        if (old1[i] <= old2[j]) {
            a[l++] = old1[i++];
            cur_inv += j;
        } else {
            a[l++] = old2[j++];
        }
    }
    while (i < k) {
        a[l++] = old1[i++];
        cur_inv += j;
    }
    while (j < k) {
        a[l++] = old2[j++];
    }
    f[n].first += cur_inv;
}


int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    int k = (1 << n);
    vector<int> a(k);
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
    }
    
    vector<pair<i64, i64>> f(n + 1, {0, 0}); 
    vector<int> rev_a(a);
    reverse(begin(rev_a), end(rev_a));   
    count_inv(&rev_a[0], n, f);
    for (int i = 0; i <= n; ++i) {
        swap(f[i].first, f[i].second);
    }
    count_inv(&a[0], n, f);

    int m;
    cin >> m;
    vector<int> q(m);
    for (int i = 0; i < m; ++i) {
        cin >> q[i];
        for (int j = 1; j <= q[i]; ++j) {
            swap(f[j].first, f[j].second);
        }
        i64 res = 0;
        for (int j = 0; j <= n; ++j) {
            res += f[j].first;
        }
        cout << res << "\n";
    }
    return 0;
}