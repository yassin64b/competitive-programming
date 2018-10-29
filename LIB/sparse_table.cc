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