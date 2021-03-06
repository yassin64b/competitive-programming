#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n, h, m;
    cin >> n >> h >> m;
    vector<int> mx(n, h);
    for (int i = 0; i < m; ++i) {
        int l, r, x;
        cin >> l >> r >> x;
        for (int j = l - 1; j < r; ++j) {
            mx[j] = min(mx[j], x);
        }
    }
    int profit = 0;
    for (int i = 0; i < n; ++i) {
        profit += mx[i] * mx[i];
    }
    cout << profit << "\n";
    
    return 0;
}