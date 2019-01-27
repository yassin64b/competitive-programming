#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> t(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }

    sort(begin(t), end(t));
    reverse(begin(t), end(t));

    double cur_t = 0.;
    for (int i = 0; i < n; ++i) {
        cur_t += t[i] + 0.01 * t[i] * cur_t + 1.;
    }
    cout.precision(17);
    cout << fixed << cur_t << "\n";

    return 0;
}