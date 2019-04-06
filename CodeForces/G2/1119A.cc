#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    int cnt1 = n - 1;
    for (int i = n - 1; i >= 0 && c[i] == c[0]; --i) {
        --cnt1;
    }
    int cnt2 = n - 1;
    for (int i = 0; i < n && c[i] == c[n - 1]; ++i) {
        --cnt2;
    }
    cout << max(cnt1, cnt2) << "\n";
    return 0;
}