#include <bits/stdc++.h>

using namespace std;

bool has_dub(const vector<int> &a) {
    int n = a.size();
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] == a[i + 1]) {
            return true;
        }
    }
    return false;
}

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int res = n;
    for (int i = 0; i <= n; ++i) {
        // keep a[0, i)
        set<int> b(begin(a), begin(a) + i);
        int m = i;
        if ((int)b.size() < m) {
            break;
        }
        res = min(res, n - m);
        for (int j = n - 1; j >= i; --j) {
            // keep a[j, n)
            b.insert(a[j]);
            ++m;
            if ((int)b.size() < m) {
                break;
            }
            res = min(res, n - m);
        }
    }
    cout << res << "\n";

    return 0;
}