#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<pair<int, int>> ab(n);
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        ab[i] = {a, b};
    }
    sort(begin(ab), end(ab), [](const auto &lhs, const auto &rhs) {
        return lhs.first - lhs.second > rhs.first - rhs.second;
    });
    long long res = 0;
    for (int i = 0; i < n; ++i) {
        res += 1LL * ab[i].first * i + 1LL * ab[i].second * (n - i - 1);
    }
    cout << res << "\n";

    return 0;
}