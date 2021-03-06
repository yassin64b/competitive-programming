#include <bits/stdc++.h>

using namespace std;

class TaskC {
private:
    int take(int x) {
        cout << x + 1 << "\n";
        cout.flush();
        return x;
    }
    int get() {
        int x;
        cin >> x;
        if (x == -1) {
            exit(0);
        }
        return x - 1;
    }
public:
    void solve(istream& in, ostream& out) {
        int n, m;
        in >> n >> m;
        vector<int> p(2 * n);
        for (int i = 0; i < 2 * n; ++i) {
            in >> p[i];
        }
        vector<int> a(m), b(m);
        for (int i = 0; i < m; ++i) {
            in >> a[i] >> b[i];
            --a[i];
            --b[i];
        }
        int t;
        in >> t;
        if (t == 1) {
            for (int i = 0; i < m; ++i) {
                if (p[a[i]] >= p[b[i]]) {
                    p[take(a[i])] = 0;
                } else {
                    p[take(b[i])] = 0;
                }
                p[get()] = 0;
            }
            vector<pair<int, int>> pind(2 * n);
            for (int i = 0; i < 2 * n; ++i) {
                pind[i] = {p[i], i};
            }
            sort(begin(pind), end(pind));
            reverse(begin(pind), end(pind));
            for (int i = 0; i < 2 * n; ++i) {
                if (p[pind[i].second]) {
                    p[take(pind[i].second)] = 0;
                    p[get()] = 0;
                }
            }
        } else {
            for (int i = 0; i < n; ++i) {
                int x = get();
                p[x] = 0;
                int ind = -1;
                if (auto it = find(begin(a), end(a), x); it != end(a)) {
                    ind = b[it - begin(a)];
                } else if (auto it = find(begin(b), end(b), x); it != end(b)) {
                    ind = a[it - begin(b)];
                }
                if (ind != -1 && p[ind]) {
                    p[take(ind)] = 0;
                } else {
                    auto it = max_element(begin(p), end(p));
                    int mx_ind = it - begin(p), mx = *it;
                    p[mx_ind] = 0;
                    auto it2 = max_element(begin(p), end(p));
                    int mx2_ind = it2 - begin(p), mx2 = *it2;
                    p[mx_ind] = mx;
                    int best_ind = mx_ind, best_val = mx - mx2;
                    for (int j = 0; j < m; ++j) {
                        if (p[a[j]] && p[b[j]]) {
                            if (p[a[j]] >= p[b[j]]) {
                                int val = p[a[j]] - p[b[j]];
                                if (val > best_val) {
                                    best_ind = a[j];
                                    best_val = val;
                                }
                            } else {
                                int val = p[b[j]] - p[a[j]];
                                if (val > best_val) {
                                    best_ind = b[j];
                                    best_val = val;
                                }
                            }
                        }
                    }
                    p[take(best_ind)] = 0;
                }
            }
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskC solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
