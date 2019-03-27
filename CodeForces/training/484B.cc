#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    constexpr int MX = 1'000'000;
    vector<int> a(2 * MX + 1, 0);
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        a[x] = 1;
    }
    vector<int> prev(2 * MX + 1, 0);
    for (int i = 1; i <= 2 * MX; ++i) {
        if (a[i - 1]) {
            prev[i] = i - 1;
        } else {
            prev[i] = prev[i - 1];
        }
    }
    int ans = 0;
    for (int i = 1; i <= MX; ++i) {
        if (!a[i]) continue;
        for (int j = 2; j * i <= 2 * MX; ++j) {
            ans = max(ans, prev[j * i] % i);
        }
    }
    cout << ans << "\n";
    return 0;
}
