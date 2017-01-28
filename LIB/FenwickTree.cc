class FenwickTree {
private:
    vector<int64_t> ft;
public:
    FenwickTree(int64_t n) {
        ft.assign(n + 1, 0);
    }
    int64_t rsq(int64_t b) {
        int sum = 0;
        for (; b; b -= (b & (-b))) {
            sum += ft[b];
        }
        return sum;
    }
    int64_t rsq(int64_t a, int64_t b) {
        if (a > b) return 0;
        return rsq(b) - rsq(a - 1);
    }
    void update(int64_t a, int64_t v) {
        for ( ; a < (int)ft.size(); a += (a & (-a))) {
            ft[a] += v;
        }
    }
    //NOTE: when using range update, rsq(x) is point query, unlike normally
    void update(int64_t a, int64_t b, int64_t v) {
        update(a, v);
        update(b + 1, -v);
    }
};