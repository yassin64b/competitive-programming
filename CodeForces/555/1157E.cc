#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }    
    multiset<int> sb;
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        sb.insert(b[i]);
    }
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        auto it1 = begin(sb);
        int v1 = (a[i] + *it1) % n;
        auto it2 = sb.lower_bound(n - a[i]);
        int v2 = n;
        if (it2 != end(sb)) {
            v2 = (a[i] + *it2) % n;
        }
        c[i] = min(v1, v2);
        if (v1 < v2) {
            sb.erase(it1);
        } else {
            sb.erase(it2);
        }
    }
    for (int x : c) {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}