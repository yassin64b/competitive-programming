#include <bits/stdc++.h>

using namespace std;

int lis(const vector<int> &a) {
    int n = a.size();
    vector<int> lis;
    lis.push_back(a[0]);
    for (int i = 1; i < n; ++i) {
        if (a[i] >= lis.back()) {
            lis.push_back(a[i]);
        } else {
            auto it = upper_bound(lis.begin(), lis.end(), a[i]);
            *it = a[i];
        }
    }
    return lis.size();
}

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int k[3];
    cin >> k[0] >> k[1] >> k[2];
    vector<int> a[3], b;
    for (int i = 0; i < 3; ++i) {
        a[i].resize(k[i]);
        for (int j = 0; j < k[i]; ++j) {
            cin >> a[i][j];
        }
        sort(begin(a[i]), end(a[i]));
        for (int x : a[i]) {
            b.push_back(x);
        }
    }
    cout << k[0] + k[1] + k[2] - lis(b) << "\n";


    return 0;
}