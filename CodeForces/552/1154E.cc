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
        --a[i];
    }

    list<int> b(begin(a), end(a));
    vector<list<int>::iterator> bit(n);
    for (auto it = begin(b); it != end(b); ++it) {
        bit[*it] = it;
    }
    
    vector<int> res(n, 0);
    for (int i = n - 1, turn = 1; i >= 0; --i) {
        if (!res[i]) {
            auto it = bit[i];
            for (int j = 0; it != end(b) && j <= k; ++j, ++it) {
                res[*it] = turn;
            }
            auto it2 = bit[i];
            for (int j = 0; j < k; ++j) {
                if (it2 == begin(b)) break;
                --it2;
                res[*it2] = turn;
            }
            b.erase(it2, it);
            turn = 3 - turn;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << res[a[i]];
    }
    cout << "\n";

    return 0;
}