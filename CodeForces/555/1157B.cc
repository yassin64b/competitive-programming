#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n;
    string a;
    cin >> n >> a;
    for (char &c : a) {
        c -= '0';
    }
    vector<int> f(10);
    for (int i = 1; i <= 9; ++i) {
        cin >> f[i];
    }
    for (int i = 0; i < n; ++i) {
        if (f[a[i]] > a[i]) { // start at i
            while (i < n && f[a[i]] >= a[i]) {
                a[i] = f[a[i]];
                ++i;
            }
            break;
        }
    }
    for (char &c : a) {
        c += '0';
    }
    cout << a << "\n";

    return 0;
}