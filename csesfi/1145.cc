#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    set<int> cur;
    for (int i = 0; i < n; ++i) {
        auto it = cur.lower_bound(x[i]);
        if (it != end(cur)) {
            cur.erase(it);
        }
        cur.insert(x[i]);
    }
    cout << cur.size() << "\n";

    return 0;
}
