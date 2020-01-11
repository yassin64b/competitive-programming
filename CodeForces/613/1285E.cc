#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n;
        cin >> n;
        vector<pair<int, int>> s(n);
        for (int i = 0; i < n; ++i) {
            cin >> s[i].first >> s[i].second;
        }
        sort(begin(s), end(s));
        vector<int> cnt(n, 0);
        priority_queue<pair<int, int>> pq;
        int num_disj = 0;
        for (int i = 0; i < n; ++i) {
            auto [li, ri] = s[i];
            bool popped = false;
            while (!pq.empty() && -pq.top().first < li) {
                pq.pop();
                popped = true;
            }
            if (pq.size() == 1U && popped) {
                int ind = pq.top().second;
                ++cnt[ind];
            } else if (pq.empty()) {
                ++num_disj;
            }
            pq.emplace(-ri, i);
        }
        int newly_added = *max_element(begin(cnt), end(cnt));
        cout << min(n - 1, num_disj + newly_added) << "\n";
    }
    int8_t x= 200;
    return 0;
}