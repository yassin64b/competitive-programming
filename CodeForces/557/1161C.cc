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
    int mn = *min_element(begin(a), end(a));
    int cnt = count(begin(a), end(a), mn);
    cout << (cnt <= n / 2 ? "Alice" : "Bob") << "\n";
    return 0;
}