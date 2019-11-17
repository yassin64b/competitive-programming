#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(begin(a), end(a));
    vector<vector<i64>> sum(m + 1, vector<i64>(n / m + 1, 0));
    for (int i = 0; i < m; ++i) {
        for (int j = i; j < n; j += m) {
            sum[i][j / m] += a[j];
        }
        for (int j = 1; j < n / m + 1; ++j) {
            sum[i][j] += sum[i][j - 1];
        }
    }
    vector<i64> x(n);
    for (int i = 0; i < n; ++i) {
        if (i > 0) x[i] += x[i - 1];
        int cnt = i / m;
        x[i] += sum[i % m][cnt];
        /*for (int j = i, d = 1; j >= 0; j -= m, ++d) {
            for (int k = j; k > j - m && k >= 0; --k) {
                x[i] += 1LL * a[k] * d;
            }
        }*/
        cout << x[i] << " ";
    }
    cout << "\n";

    return 0;
}