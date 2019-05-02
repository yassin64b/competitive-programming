#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    for (int cnt = 0; cnt < m; ++cnt) {
        vector<int> inv_col(m, 0);
        for (int j = 0; j < cnt; ++j) {
            inv_col[j] = (a[0][j] != 0);
        }
        for (int j = cnt; j < m; ++j) {
            inv_col[j] = (a[0][j] != 1);
        }
        vector<int> inv_row(n, 0);
        bool ok = true;
        for (int i = 1; ok && i < n; ++i) {
            set<int> vals;
            for (int j = 0; j < m; ++j) {
                vals.insert((inv_col[j] ? !a[i][j] : a[i][j]));
            }
            if (vals.size() > 1U) {
                ok = false;
            } else if (*vals.begin() == 0) {
                inv_row[i] = 1;
            }
        }
        if (ok) {
            cout << "YES\n";
            for (int x : inv_row) {
                cout << x;
            }
            cout << "\n";
            for (int x : inv_col) {
                cout << x;
            }
            cout << "\n";
            return 0;
        }
    }
    {
        //int cnt = m;
        vector<int> inv_col(m, 0);
        for (int j = 0; j < m; ++j) {
            inv_col[j] = (a[0][j] != 0);
        }
        vector<int> inv_row(n, 0);
        bool ok = true;
        int phase = 0;
        for (int i = 1; ok && i < n; ++i) {
            if (phase == 0) {
                int first1 = n, last0 = -1;
                for (int j = 0; j < m; ++j) {
                    int val = (inv_col[j] ? !a[i][j] : a[i][j]);
                    if (val == 1) first1 = min(first1, j);
                    else last0 = j;
                }
                if (first1 == 0) {
                    inv_row[i] = 1;
                    first1 = n, last0 = -1;
                    for (int j = 0; j < m; ++j) {
                        int val = (inv_col[j] ? a[i][j] : !a[i][j]);
                        if (val == 1) first1 = min(first1, j);
                        else last0 = j;
                    }
                }
                if (last0 > first1) {
                    ok = false;
                }
                if (first1 < n) {
                    phase = 1;
                }    
            } else {
                set<int> vals;
                for (int j = 0; j < m; ++j) {
                    vals.insert((inv_col[j] ? !a[i][j] : a[i][j]));
                }
                if (vals.size() > 1U) {
                    ok = false;
                } else if (*vals.begin() == 0) {
                    inv_row[i] = 1;
                } 
            }
        }
        if (ok) {
            cout << "YES\n";
            for (int x : inv_row) {
                cout << x;;
            }
            cout << "\n";
            for (int x : inv_col) {
                cout << x;
            }
            cout << "\n";
            return 0;
        }   
    }
    cout << "NO\n";

    return 0;
}