#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<bool>> v(n + 1, vector<bool>(n + 1));
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < n / 4; ++j) {
            int x = (s[j] >= 'A') ? (s[j] - 'A' + 10) : (s[j] - '0');
            for (int k = 0; k < 4; ++k) {
                v[i + 1][j * 4 + (3 - k) + 1] = (x & (1 << k));
            }
        }
    }   

    vector<vector<int>> sum(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            sum[i][j] = v[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }

    for (int x = n; x >= 2; --x) {
        if (n % x) continue;
        bool ok = true;
        for (int a = 1; ok && a <= n; a += x) {
            for (int b = 1; ok && b <= n; b += x) {
                int c = a + x - 1, d = b + x - 1;
                int cur = sum[c][d] - sum[a - 1][d] - sum[c][b - 1] + sum[a - 1][b - 1];
                if (cur != 0 && cur != x * x) {
                    ok = false;
                }
            }
        }
        if (ok) {
            cout << x << "\n";
            return 0;
        }
    }

    cout << 1 << "\n"; 
    
    return 0;
}