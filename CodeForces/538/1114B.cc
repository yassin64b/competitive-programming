#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> b(a);
    sort(begin(b), end(b));
    reverse(begin(b), end(b));
    multiset<int> take;
    i64 sum = 0;
    for (int i = 0; i < k * m; ++i) {
        take.insert(b[i]);
        sum += b[i];
    }
    cout << sum << "\n";
    int cur_cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (take.count(a[i])) {
            take.erase(take.find(a[i]));
            ++cur_cnt;
            if (cur_cnt > m) {
                cur_cnt = 1;
                cout << i << " ";
            }
        }
    }
    cout << "\n";

    return 0;
}