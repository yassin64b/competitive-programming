#include <bits/stdc++.h>

using namespace std;

constexpr int n = 5;

void check(int b[n][n], vector<int> &res, int &a) {
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        for (int j = 0; j < n; ++j) {
            cnt += (b[i][j] != 0);
        }
        if (cnt < a) {
            a = cnt;
            res.clear();
            for (int j = 0; j < n; ++j) {
                if (b[i][j] != 0) {
                    res.push_back(b[i][j]);
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        for (int j = 0; j < n; ++j) {
            cnt += (b[j][i] != 0);
        }
        if (cnt < a) {
            a = cnt;
            res.clear();
            for (int j = 0; j < n; ++j) {
                if (b[j][i] != 0) {
                    res.push_back(b[j][i]);
                }
            }
        }
    }
    {
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            cnt += (b[i][i] != 0);
        }
        if (cnt < a) {
            a = cnt;
            res.clear();
            for (int i = 0; i < n; ++i) {
                if (b[i][i] != 0) {
                    res.push_back(b[i][i]);
                }
            }
        }
    }
    {
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            cnt += (b[i][n - 1 - i] != 0);
        }
        if (cnt < a) {
            a = cnt;
            res.clear();
            for (int i = 0; i < n; ++i) {
                if (b[i][n - 1 - i] != 0) {
                    res.push_back(b[i][n - 1 - i]);
                }
            }
        }
    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    
    int b[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> b[i][j];
        }
    }
    vector<int> res;
    int a = n + 1;
    check(b, res, a);

    cout << a << "\n";
    for (int x : res) {
        cout << x << " ";
    }
    cout << "\n";


    return 0;
}