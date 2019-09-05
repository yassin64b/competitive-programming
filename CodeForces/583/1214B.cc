#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int b, g, n;
    cin >> b >> g >> n;
    int res = 0;
    for (int num_b = 0; num_b <= b && num_b <= n; ++num_b) {
        int num_g = n - num_b;
        if (num_g >= 0 && num_g <= g) {
            ++res;
        }
    }
    cout << res << "\n";

    return 0;
}