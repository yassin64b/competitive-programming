#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    vector<int> a;
    for (int i = 1; i < n; ++i) {
        a.push_back(b[i] - b[i - 1] - 1);
    }
    sort(begin(a), end(a));
    reverse(begin(a), end(a));

    int sum = 0;
    for (int i = 0; i < k - 1; ++i) {
        sum += max(0, a[i]);
    }
    cout << b[n - 1] - b[0] + 1 - sum << "\n";

    return 0;
}