#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }   

    vector<int> odd(n), even(n);
    odd[0] = 0;
    even[0] = s[0];
    for (int i = 1; i < n; ++i) {
        odd[i] = (i % 2 == 1 ? s[i] : 0) + odd[i - 1];
        even[i] = (i % 2 == 0 ? s[i] : 0) + even[i - 1];
    }

    int mx = 0;
    for (int i = 0; i < n; ++i) {
        int cur = 0;
        if (i % 2 == 0) {
            cur += odd[n - 1] - odd[i];
            cur += (i - 1 >= 0 ? even[i - 1] : 0);
        } else {
            cur += even[n - 1] - even[i];
            cur += (i - 1 >= 0 ? odd[i - 1] : 0); 
        }
        mx = max(mx, cur);
    }

    cout << mx << "\n";

    return 0;
}