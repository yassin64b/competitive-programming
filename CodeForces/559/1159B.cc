#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int k = 1'000'000'000;
    for (int i = 0; i < n; ++i) {
        int mx_dist = max(n - 1 - i, i);
        int mx_k = a[i] / mx_dist;
        k = min(k, mx_k);
    }
    cout << k << "\n";
    
    return 0;
}