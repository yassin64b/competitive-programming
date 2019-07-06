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
    if (a[n - 1] >= a[n - 2] + a[n - 3]) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        cout << a[n - 2] << " " << a[n - 1];
        for (int i = n - 3; i >= 0; --i) {
            cout << " " << a[i];
        }
        cout << "\n";
    }


    return 0;
}