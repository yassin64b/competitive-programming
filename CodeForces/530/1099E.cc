#include <bits/stdc++.h>

using namespace std;

int calc_cost(char a, char b, const string &t, int m) {
    int cost = 0;
    for (int j = 0; j < m; ++j) {
        cost += (j % 2 == 0 && t[j] != b);
        cost += (j % 2 != 0 && t[j] != a);
    }
    return cost;
}
void check(char c1, char c2, char c3, char c4, vector<string> &res, 
           int &mn_cost, int n, int m, bool rev, const vector<string> &t) {
    vector<string> tmp(n, string(m, ' '));
    int cur_cost = 0;
    for (int i = 0; i < n; ++i) {
        char a = (i % 2 == 0 ? c1 : c3);
        char b = (i % 2 == 0 ? c2 : c4);

        int tmp_cost1 = calc_cost(a, b, t[i], m);

        swap(a, b);
        int tmp_cost2 = calc_cost(a, b, t[i], m);

        cur_cost += min(tmp_cost1, tmp_cost2);
        if (tmp_cost1 < tmp_cost2) {
            swap(a, b);
        }

        for (int j = 0; j < m; ++j) {
            tmp[i][j] = (j % 2 == 0 ? b : a);
        }
    }
    if (cur_cost < mn_cost) {
        mn_cost = cur_cost;
        if (rev) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    res[j][i] = tmp[i][j];
                }
            }
        } else {
            res = tmp;
        }
    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<string> t(n), t_rev(m, string(n, ' '));
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            t_rev[j][i] = t[i][j];
        }
    }
    
    const string s{'A', 'C', 'G', 'T'};
    set<char> poss_c(begin(s), end(s));

    int mn_cost = n * m + 1;
    vector<string> res(n, string(m, ' ')); 
    for (int i = 0; i < 4; ++i) {
        poss_c.erase(s[i]);
        for (int j = i + 1; j < 4; ++j) {
            poss_c.erase(s[j]);
            check(s[i], s[j], *begin(poss_c), *++begin(poss_c), res, 
                  mn_cost, n, m, false, t);
            check(s[i], s[j], *begin(poss_c), *++begin(poss_c), res,
                  mn_cost, m, n, true, t_rev);
            poss_c.insert(s[j]);
        }
        poss_c.insert(s[i]);
    }

    for (const auto &str : res) {
        cout << str << "\n";
    }

    return 0;
}