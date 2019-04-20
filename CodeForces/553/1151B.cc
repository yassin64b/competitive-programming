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
    vector<int> c(n, 0);
    int cur_xor = 0;
    for (int i = 0; i < n; ++i) {
        cur_xor ^= a[i][0];
    }
    for (int i = 0; cur_xor == 0 && i < n; ++i) {
        for (int j = 1; cur_xor == 0 && j < m; ++j) {
            if (a[i][j] != a[i][0]) {
                c[i] = j;
                cur_xor ^= a[i][j];
                cur_xor ^= a[i][0];
            }
        }
    }
    if (cur_xor == 0) {
        cout << "NIE\n";
    } else {
        cout << "TAK\n";
        for (int j : c) {
            cout << j + 1 << " ";
        }
        cout << "\n";
    }

    return 0;
}