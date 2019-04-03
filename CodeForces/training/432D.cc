#include <bits/stdc++.h>

using namespace std;

// taken from https://cp-algorithms.com/string/z-function.html
vector<int> z_function(const string &s) {
    int n = s.size();
    vector<int> z(n);
    z[0] = n;
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    string s;
    cin >> s;
    int n = s.size();
    vector<int> z(z_function(s));
    vector<int> vals(z);
    sort(begin(vals), end(vals));

    vector<pair<int, int>> res;
    for (int i = 1; i <= n; ++i) {
        if (z[n - i] == i) {
            auto it = lower_bound(begin(vals), end(vals), i);
            int cnt = end(vals) - it;
            res.emplace_back(i, cnt);
        }
    }
    cout << res.size() << "\n";
    for (auto [x, y] : res) {
        cout << x << " " << y << "\n";
    }

    return 0;
}