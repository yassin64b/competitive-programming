#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    set<pair<int, int>> s;
    for (int i = 0; i < m; ++i) {
        cin >> a[i] >> b[i];
        --a[i];
        --b[i];
        if (a[i] > b[i]) {
            swap(a[i], b[i]);
        }
        s.emplace(a[i], b[i]);
    }   
    for (int k = 1; k < n; ++k) {
        if (n % k == 0) {
            bool ok = true;
            for (int i = 0; i < m; ++i) {
                int na = (a[i] + k) % n, nb = (b[i] + k) % n;
                if (na > nb) {
                    swap(na, nb);
                }
                if (!s.count(pair(na, nb))) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                cout << "Yes\n";
                return 0;
            }
        }
    }
    cout << "No\n";
    return 0;
}