#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> bt(n);
    for (int i = 0; i < n; ++i) {
        cin >> bt[i].second >> bt[i].first;
    }
    sort(begin(bt), end(bt));
    reverse(begin(bt), end(bt));
    long long mx = 0, cur_len = 0;
    priority_queue<int> pq;
    for (int i = 0; i < n; ++i) {
        cur_len += bt[i].second;
        pq.push(-bt[i].second);
        if ((int)pq.size() > k) {
            int x = -pq.top();
            pq.pop();
            cur_len -= x;
        }
        mx = max(mx, cur_len * bt[i].first);
    }
    cout << mx << "\n";

    return 0;
}