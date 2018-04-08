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