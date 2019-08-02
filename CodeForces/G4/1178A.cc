#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
        sum += a[i].first;
    }
    sort(begin(a) + 1, end(a));
    int mx = a[0].first / 2;
    vector<pair<int, int>> coal{a[0]};
    int coal_sum = a[0].first;
    for (int i = 1; i < n && a[i].first <= mx; ++i) {
        coal.push_back(a[i]);
        coal_sum += a[i].first;
    }
    if (2 * coal_sum > sum) {
        cout << coal.size() << "\n";
        for (auto [ai, i] : coal) {
            cout << i + 1 << " ";
        }
        cout << "\n";
    } else {
        cout << 0 << "\n";
    }

    return 0;
}