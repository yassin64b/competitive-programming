#include <bits/stdc++.h>

using namespace std;

class SparseTable {
private:
    vector<int> a_;
    vector<vector<int>> t_;
    int (*f_)(int, int);
public:
    SparseTable(vector<int> a, int (*f)(int, int)) : a_(a), f_(f) {
        int n = a_.size();
        int logn = ceil(log2(n));
        if ((1 << logn) <= n) ++logn;
        t_.assign(n, vector<int>(logn));
        for (int i = 0; i < n; ++i) {
            t_[i][0] = a_[i];
        }
        for (int j = 1; (1 << j) <= n; ++j) {
            for (int i = 0; i + (1 << j) <= n; ++i) {
                int k1 = t_[i][j - 1], k2 = t_[i + (1 << (j - 1))][j - 1];
                t_[i][j] = f_(k1, k2);
            }
        }
    }
    int query(int i, int j) {
        int len = j - i + 1;
        int k = log2(len);
        return f_(t_[i][k], t_[j - (1 << k) + 1][k]);
    }
};

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> P(N);
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
    }
    SparseTable st(P, [](int a, int b) { return max(a, b); });
    long long res = 0;
    for (int i = 0; i < N; ++i) {
        if (i > 0) { // max to the left
            int low = 0, high = i - 1, mx_ind = -1;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (st.query(mid, i - 1) > P[i]) {
                    mx_ind = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            if (mx_ind != -1) {
                low = 0; high = mx_ind - 1;
                int from_ind = mx_ind;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    if (st.query(mid, mx_ind - 1) > P[i]) {
                        low = mid + 1;
                    } else {
                        from_ind = mid;
                        high = mid - 1;
                    }
                }
                low = i + 1; high = N - 1;
                int upto_ind = i;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    if (st.query(i + 1, mid) > P[i]) {
                        high = mid - 1;
                    } else {
                        upto_ind = mid;
                        low = mid + 1;
                    }
                }
                int len1 = mx_ind - from_ind + 1;
                int len2 = upto_ind - i + 1;
                res += 1LL * len1 * len2 * P[i];
            }
        }
        
        if (i < N - 1) { // max to the right
            int low = i + 1, high = N - 1, mx_ind = N;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (st.query(i + 1, mid) > P[i]) {
                    mx_ind = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            if (mx_ind < N) {
                low = 0; high = i - 1;
                int from_ind = i;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    if (st.query(mid, i - 1) > P[i]) {
                        low = mid + 1;
                    } else {
                        from_ind = mid;
                        high = mid - 1;
                    }
                }
                low = mx_ind + 1; high = N - 1;
                int upto_ind = mx_ind;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    if (st.query(mx_ind + 1, mid) > P[i]) {
                        high = mid - 1;
                    } else {
                        upto_ind = mid;
                        low = mid + 1;
                    }
                }
                int len1 = i - from_ind + 1;
                int len2 = upto_ind - mx_ind + 1;
                res += 1LL * len1 * len2 * P[i];
            }
        }
        
    }
    cout << res << "\n";

    return 0;
}