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
    sort(begin(a), end(a));
    int nxt = 1;
    for (int i = 0; i < n; ++i) {
        nxt += (a[i] >= nxt);
    }
    cout << nxt - 1 << "\n";

    return 0;
}