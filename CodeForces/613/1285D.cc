#include <bits/stdc++.h>
 
using namespace std;
 
int recurse(int shift, const vector<int> &a) {
    if (shift < 0) {
        return 0;
    }
    vector<int> one, zero;
    int mask = (1 << shift);
    for (int x : a) {
        if (x & mask) {
            one.push_back(x);
        } else {
            zero.push_back(x);
        }
    }
    if (zero.empty()) {
        return recurse(shift - 1, one);
    } else if (one.empty()) {
        return recurse(shift - 1, zero);
    }
    int r1 = recurse(shift - 1, zero);
    int r2 = recurse(shift - 1, one);
    return min(r1, r2) + mask;
}
int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
 
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cout << recurse(29, a) << "\n";     
    return 0;
}