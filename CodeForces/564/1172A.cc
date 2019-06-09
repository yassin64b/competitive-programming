#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    int res = 1'000'000'000;
    {
        int pos1 = -1;
        for (int i = 0; i < n; ++i) {
            if (b[i] == 1) {
                pos1 = i;
            }
        }
        int nxt = 2;
        bool ok = (pos1 != -1);
        for (int i = pos1 + 1; ok && i < n; ++i) {
            if (b[i] == nxt) {
                ++nxt;
            } else {
                ok = false;
            }
        }
        if (ok) {
            set<int> have;
            for (int x : a) {
                if (x) {
                    have.insert(x);
                }
            }
            ok = true;
            for (int i = nxt, j = 0; ok && i <= n; ++i) {
                if (!have.count(i)) {
                    ok = false;
                } else {
                    have.insert(b[j]);
                    ++j;
                }
            }
            if (ok) {
                res = min(res, n - nxt + 1);
            }
        }
    }
    {
        int t = n;
        for (int j = 0; j < n; ++j) {
            if (b[j]) {
                int after = n - b[j];
                t = max(t, j + 1 + after + 1);
            }
        }
        res = min(res, t);
    }

    cout << res << "\n";

    return 0;
}