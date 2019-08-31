#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    constexpr int MXV = 200'000;
    vector<vector<int>> costs_to_get(MXV + 1);
    for (int x : a) {
        int cur_cost = 0;
        do {
            costs_to_get[x].push_back(cur_cost);
            x /= 2;
            ++cur_cost;
        } while (x);
    }
    int mn_cost = 10'000'000;
    for (auto &v : costs_to_get) {
        if ((int)v.size() >= k) {
            sort(begin(v), end(v));
            mn_cost = min(mn_cost, accumulate(begin(v), begin(v) + k, 0));
        }
    }
    cout << mn_cost << "\n";

    return 0;
}