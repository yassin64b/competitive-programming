#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> x(n), y(n), a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }

    for (int i = 0; i < n; ++i) {
        int Tx = x[0] + a[i], Ty = y[0] + b[i];
        set<pair<int, int>> av;
        for (int j = 0; j < n; ++j) {
            if (j != i) {
                av.emplace(a[j], b[j]);
            }
        }
        bool ok = true;
        for (int j = 1; j < n; ++j) {
            int needx = Tx - x[j], needy = Ty - y[j];
            if (av.count(pair(needx, needy))) {
                av.erase(pair(needx, needy));
            } else {
                ok = false;
            }
        }
        if (ok) {
            cout << Tx << " " << Ty << "\n";
            return 0;
        }
    }

    return 0;
}