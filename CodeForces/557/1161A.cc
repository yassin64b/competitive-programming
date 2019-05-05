#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    vector<int> x(k);
    for (int i = 0; i < k; ++i) {
        cin >> x[i];
    }
    vector<int> last_occ(n + 1, -1), first_occ(n + 1, k);
    for (int i = 0; i < k; ++i) {
        last_occ[x[i]] = i;
    }
    for (int i = k - 1; i >= 0; --i) {
        first_occ[x[i]] = i;
    }
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = -1; j <= 1; ++j) {
            int y = i + j;
            if (y >= 1 && y <= n) {
                if (first_occ[i] > last_occ[y]) {
                    ++res;
                }
            }
        }
    }
    cout << res << "\n";

    return 0;
}