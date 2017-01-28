inline int64_t LSOne(int64_t b) {
    return (b & (-b));
}

class FenwickTree {
private:
    vector<int64_t> ft;
public:
    FenwickTree(int64_t n) {
        ft.assign(n + 1, 0);
    }
    int64_t rsq(int64_t b) {
        int sum = 0;
        for (; b; b -= LSOne(b)) {
            sum += ft[b];
        }
        return sum;
    }
    int64_t rsq(int64_t a, int64_t b) {
        if (a > b) return 0;
        return rsq(b) - rsq(a - 1);
    }
    void adjust(int64_t k, int64_t v) {
        for ( ; k < (int)ft.size(); k += LSOne(k)) {
            ft[k] += v;
        }
    }
};