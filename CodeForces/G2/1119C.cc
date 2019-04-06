#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> A(n, vector<int>(m)), B(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> B[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            A[i][j] = (A[i][j] != B[i][j]);
        }
    }
    vector<int> row_sum(n, 0), col_sum(m, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            row_sum[i] += A[i][j];
            col_sum[j] += A[i][j];
        }
    }
    bool ok = true;
    for (int i = 0; i < n; ++i) {
        if (row_sum[i] % 2) {
            ok = false;
        }
    }
    for (int j = 0; j < m; ++j) {
        if (col_sum[j] % 2) {
            ok = false;
        }
    }
    cout << (ok ? "Yes" : "No") << "\n";
    
    return 0;
}