#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int INF = 1'000'000'001;

/*class SegmentTree { // passes, but nearly too slow
private:
    vector<pair<int, int>> _mx;
    int _n;
    int lc(int node) { return 2 * node; }
    int rc(int node) { return 2 * node + 1; }
    int mid(int a, int b) { return (a + b) / 2; }
    int num(int a, int b) { return b - a + 1; }
    /*void build(int node, int l, int r, const vector<int> &a) {
        if (l == r) {
            _mx[node] = a[l];
        } else {
            build(lc(node), l, mid(l, r), a);
            build(rc(node), mid(l, r) + 1, r, a);
            update(node);
        }
    }*/
    /*void update(int node) {
        _mx[node] = max(_mx[lc(node)], _mx[rc(node)]);
    }
    void update_range(int node, int l, int r, int i, pair<int, int> val) {
        if (l > r || l > i || r < i) {
            return;
        } else if (i == l && i == r) {
            _mx[node] = max(_mx[node], val);
            return;
        }
        update_range(lc(node), l, mid(l, r), i, val);
        update_range(rc(node), mid(l, r) + 1, r, i, val);
        update(node);
    }
    pair<int, int> query_range(int node, int l, int r, int i, int j) {
        if (l > r || l > j || r < i) {
            return {-INF, -1};
        } else if (i <= l && r <= j) {
            return _mx[node];
        }
        pair<int, int> res = query_range(lc(node), l, mid(l, r), i, j);
        return max(res, query_range(rc(node), mid(l, r) + 1, r, i, j));
    }
public:
    SegmentTree(int n) : _n(n) {
        _mx.assign(4 * _n + 1, {-INF, -1});
        //build(1, 0, _n - 1, a);
    }
    void update(int i, pair<int, int> val) {
        update_range(1, 0, _n - 1, i, val);
    }
    pair<int, int> query_range(int i, int j) {
        return query_range(1, 0, _n - 1, i, j);
    }
};*/

// faster segtree
const int N = 8e5;  // limit for array size
int len = N;  // array size
pair<int, int> t[2 * N];

void build() {  // build the tree
    for (int i = 0; i < 2 * N; ++i) {
        t[i] = {-INF, -1};
    }
}

void modify(int p, pair<int, int> value) {  // set value at position p
    t[p + len] = max(t[p + len], value);
    for (p += len; p > 1; p >>= 1) t[p>>1] = max(t[p], t[p^1]);
}

pair<int, int> query(int l, int r) {  // max on interval [l, r)
    pair<int, int> res = {-INF, -1};
    for (l += len, r += len; l < r; l >>= 1, r >>= 1) {
        if (l&1) res = max(res, t[l++]);
        if (r&1) res = max(res, t[--r]);
    }
    return res;
}

class A542 {
public:
    void solve(istream& in, ostream& out) {
        int n, m;
        in >> n >> m;
        //len = n + m;
        vector<tuple<int, int, int>> lr(n);
        vector<int> vals;
        for (int i = 0; i < n; ++i) {
            in >> get<0>(lr[i]) >> get<1>(lr[i]);
            get<2>(lr[i]) = i;
            vals.push_back(get<0>(lr[i]));
            vals.push_back(get<1>(lr[i]));
        }
        vector<tuple<int, int, int, int>> abc(m);
        for (int i = 0; i < m; ++i) {
            int a, b, c;
            in >> a >> b >> c;
            abc[i] = {a, b, c, i};
            vals.push_back(a);
            vals.push_back(b);
        }
        // range compression
        sort(begin(vals), end(vals));
        map<int, int> comp;
        int id = 0;
        for (int i = 0; i < (int)vals.size(); ++i) {
            if (i > 0 && vals[i] != vals[i - 1])
                comp[vals[i]] = ++id;
        }
        i64 res = 0;
        int indi = -1, indj = -1;
        
        { // check [a,b] completely contained in [l,r]
            sort(begin(lr), end(lr));
            sort(begin(abc), end(abc));
            for (int i = 0, j = 0, mxr = -1, ind = -1; j < m; ++j) {
                while (i < n && get<0>(lr[i]) <= get<0>(abc[j])) {
                    if (get<1>(lr[i]) > mxr) {
                        mxr = get<1>(lr[i]);
                        ind = get<2>(lr[i]);
                    }
                    ++i;
                }
                int a, b, c, k;
                tie(a, b, c, k) = abc[j];
                if (b <= mxr && 1LL * (b - a) * c > res) {
                    res = 1LL * (b - a) * c;
                    indi = ind;
                    indj = k;
                }
            }
        }
        
        
    
        { // check partial left
            sort(begin(lr), end(lr), [](auto p1, auto p2) {
                return get<0>(p1) < get<0>(p2);
            });
            sort(begin(abc), end(abc), [](auto t1, auto t2) {
                return get<0>(t1) < get<0>(t2);
            });
            //SegmentTree st(id);
            build();
            for (int i = 0, j = 0; j < m; ++j) {
                while (i < n && get<0>(lr[i]) < get<0>(abc[j])) {
                    int val = get<1>(lr[i]);
                    int ind = comp[get<1>(lr[i])];
                    //st.update(ind, {val, get<2>(lr[i])});
                    modify(ind, {val, get<2>(lr[i])});
                    ++i;
                }
            
                int a, b, c, k;
                tie(a, b, c, k) = abc[j];
                int ind1 = comp[a], ind2 = comp[b];
                //pair<int, int> p = st.query_range(ind1, ind2);
                pair<int, int> p = query(ind1, ind2 + 1);
                int val = p.first - a;
                int ind = p.second;
                if (1LL * val * c > res) {
                    res = 1LL * val * c;
                    indi = ind;
                    indj = k;
                }
            }
        }
    
        { // check [l,r] completely contained in [a,b]
            sort(begin(lr), end(lr), [](auto p1, auto p2) {
                return get<1>(p1) < get<1>(p2);
            });
            sort(begin(abc), end(abc), [](auto t1, auto t2) {
                return get<1>(t1) < get<1>(t2);
            });
            //SegmentTree st(id);
            build();
            for (int i = 0, j = 0; j < m; ++j) {
                while (i < n && get<1>(lr[i]) <= get<1>(abc[j])) {
                    int val = get<1>(lr[i]) - get<0>(lr[i]);
                    int ind = comp[get<0>(lr[i])];
                    //st.update(ind, {val, get<2>(lr[i])});
                    modify(ind, {val, get<2>(lr[i])});
                    ++i;
                }
            
                int a, b, c, k;
                tie(a, b, c, k) = abc[j];
                int ind1 = comp[a], ind2 = comp[b];
                //pair<int, int> p = st.query_range(ind1, ind2);
                pair<int, int> p = query(ind1, ind2 + 1);
                int val = p.first;
                int ind = p.second;
                if (1LL * val * c > res) {
                    res = 1LL * val * c;
                    indi = ind;
                    indj = k;
                }
            }
        }
    
        { // check partial right
            /*sort(begin(lr), end(lr), [](auto p1, auto p2) { // still sorted from prev
                return get<1>(p1) < get<1>(p2);
            });
            sort(begin(abc), end(abc), [](auto t1, auto t2) {
                return get<1>(t1) < get<1>(t2);
            });*/
            //SegmentTree st(id);
            build();
            for (int i = n - 1, j = m - 1; j >= 0; --j) {
                while (i >= 0 && get<1>(lr[i]) > get<1>(abc[j])) {
                    int val = -get<0>(lr[i]);
                    int ind = comp[get<0>(lr[i])];
                    //st.update(ind, {val, get<2>(lr[i])});
                    modify(ind, {val, get<2>(lr[i])});
                    --i;
                }
            
                int a, b, c, k;
                tie(a, b, c, k) = abc[j];
                int ind1 = comp[a], ind2 = comp[b];
                //pair<int, int> p = st.query_range(ind1, ind2);
                pair<int, int> p = query(ind1, ind2 + 1);
                int val = b + p.first;
                int ind = p.second;
                if (1LL * val * c > res) {
                    res = 1LL * val * c;
                    indi = ind;
                    indj = k;
                }
            }
        }
        
        out << res << "\n";
        if (res) out << indi + 1 << " " << indj + 1 << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    A542 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
