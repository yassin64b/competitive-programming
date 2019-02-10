#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int b, k;
    cin >> b >> k;
    vector<int> a(k);
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
    }

    int par_b = 1;
    int res = 0;
    for (int i = k - 1; i >= 0; --i) {
        int cur = a[i] * par_b % 2;
        res = (res + cur) % 2;
        par_b = (par_b * b) % 2;
    }
    cout << (res ? "odd" : "even") << "\n";

    return 0;
}