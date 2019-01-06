#include <bits/stdc++.h>

using namespace std;

vector<int> lis(const vector<int> &a, vector<int> &ind, vector<int> &p,
                vector<vector<int>> &dec_seq) {
    int n = a.size();
    vector<int> lis;
    lis.push_back(a[0]);
    dec_seq.push_back({a[0]});
    p[0] = -1;
    ind[0] = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] >= lis.back()) {
            int pos = lis.size();
            ind[pos] = i;
            if (pos > 0) {
                p[i] = ind[pos - 1];
            } else {
                p[i] = -1;   
            }
            lis.push_back(a[i]);
            dec_seq.push_back({a[i]});
        } else {
            auto it = upper_bound(lis.begin(), lis.end(), a[i]);
            int pos = it - begin(lis);
            ind[pos] = i;
            if (pos > 0) {
                p[i] = ind[pos - 1];
            } else {
                p[i] = -1;   
            }
            *it = a[i];
            assert(lis.size() == dec_seq.size());
            dec_seq[pos].push_back(a[i]);
        }
    }
    vector<int> res(lis.size());
    for (int j = (int)lis.size() - 1, i = ind[j]; i >= 0 && j >= 0; i = p[i], --j) {
        res[j] = a[i];
    }
    return res;
}

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<vector<int>> res;
        while (!a.empty()) {
            int m = a.size();
            vector<int> p(m), ind(m);
            vector<vector<int>> dec_seq;
            vector<int> b = lis(a, ind, p, dec_seq);
            int k = b.size();
            if (k * (k + 1) / 2 >= m) {
                res.push_back(b);
                vector<int> na;
                for (int i = 0, j = 0; i < m; ++i) {
                    if (j < (int)b.size() && a[i] == b[j]) {
                        ++j;
                    } else {
                        na.push_back(a[i]);
                    }
                }
                a = na;
            } else {
                for (const auto &v : dec_seq) {
                    res.push_back(v);
                }
                break;
            }
        }
        cout << res.size() << "\n";
        for (const auto &v : res) {
            cout << v.size();
            for (int x : v) {
                cout << " " << x;
            }
            cout << "\n";
        }

    }

    return 0;
}