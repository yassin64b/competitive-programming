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
    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > 0) {
            ++res;
            for (int j = i + 1; j < n; ++j) {
                if (a[j] % a[i] == 0) {
                    a[j] = 0;
                }
            }
        }
    }
    cout << res << "\n";
    
    return 0;
}