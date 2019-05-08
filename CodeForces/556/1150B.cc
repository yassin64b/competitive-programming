#include <bits/stdc++.h>

using namespace std;

int cx[]{+1, +1, +1, +2};
int cy[]{-1, 0, +1, 0};

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<string> g(n);
    for (int i = 0; i < n; ++i) {
        cin >> g[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (g[i][j] == '.') {
                g[i][j] = '#';
                bool ok = true;
                for (int k = 0; ok && k < 4; ++k) {
                    int x = i + cx[k], y = j + cy[k];
                    if (x >= 0 && x < n && y >= 0 && y < n && g[x][y] == '.') {
                        g[x][y] = '#';
                    } else {
                        ok = false;
                    }
                }
                if (!ok) {
                    cout << "NO\n";
                    return 0;
                }
            }
        }
    }
    cout << "YES\n";
    return 0;
}