#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

i64 range_sum(int i, int j, const vector<i64> &psum, int n) {
    //cout << "sum " << i << " " << j << endl;
    if (j < i) return 0;
    return psum[min(j + 1, n - 1)] - psum[i];
}

bool check(int nd, const vector<int> &a, vector<i64> &psum, int n) {
    vector<int> d(a);
    d.push_back(nd);
    sort(begin(d), end(d));
    reverse(begin(d), end(d));
    int m = n + 1;
    for (int i = 0; i < m; ++i) {
        psum[i + 1] = psum[i] + d[i];
    }
    i64 left = 0;
    for (int i = 0, ind = m; i < m; ++i) {
        left += d[i];
        int k = i + 1;
        i64 cur_r = 1LL * k * (k - 1);
        while (ind >= 1 && d[ind - 1] < k) {
            --ind;
        }
        cur_r += 1LL * max(0, ind - 1 - i) * k + range_sum(ind, m, psum, m + 1);
        if (left > cur_r) {
            return false;
        }
    }
    return true;
}

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    i64 asum = accumulate(begin(a), end(a), 0LL);
    vector<i64> psum(n + 2);

    int start = -1;
    { // get any starting value or return -1
        vector<int> d(a);
        sort(begin(d), end(d));
        reverse(begin(d), end(d));
        int m = n;
        for (int i = 0; i < m; ++i) {
            psum[i + 1] = psum[i] + d[i];
        }
        i64 left = 0;
        for (int i = 0, ind = m; i < m; ++i) {
            left += d[i];
            int k = i + 1;
            i64 cur_r = 1LL * k * (k - 1);
            while (ind >= 1 && d[ind - 1] < k) {
                --ind;
            }
            cur_r += 1LL * max(0, ind - 1 - i) * k + range_sum(ind, m, psum, m +1);
            if (left > cur_r) {
                int nd = left - cur_r;
                if (nd > k) {
                    cout << -1 << "\n";
                    return 0;
                } else {
                    start = max(start, nd);
                }
            }
        }
        if (start == -1) {
            start = 0;
        }
    }
    
    // find minimum possible value
    int low = 0, high = start, mn = high + 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int nd = mid - (asum + mid) % 2;
        if (nd < 0) {
            low = mid + 1;
        } else {
            bool ok = check(nd, a, psum, n);
            if (ok) {
                high = mid - 1;
                mn = nd;
            } else {
                low = mid + 1;
            }
        }
    }

    // find maximum possible value
    low = mn, high = n;
    int mx = low - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int nd = mid - (asum + mid) % 2;
        if (nd < 0) {
            low = mid + 1;
        } else {
            bool ok = check(nd, a, psum, n);
            if (ok) {
                low = mid + 1;
                mx = nd;
            } else {
                high = mid - 1;
            }
        }
    }

    assert(mn <= mx);
    // every value in between s.t. sum of degrees is even is valid
    for (int i = mn; i <= mx; i += 2) {
        cout << i << " ";
    }
    cout << "\n";

    return 0;
}