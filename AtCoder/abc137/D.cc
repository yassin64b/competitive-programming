#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> ab(N);
    for (int i = 0; i < N; ++i) {
        cin >> ab[i].first >> ab[i].second;
    }
    // sort by reward B, but do task as late as possible
    sort(begin(ab), end(ab), [](const auto &lhs, const auto &rhs) {
        return lhs.second > rhs.second 
                || (lhs.second == rhs.second && lhs.first < rhs.first);
    });
    int res = 0;
    set<int> avail;
    for (int i = 0; i < M; ++i) {
        avail.insert(i);
    }
    for (const auto p : ab) {
        int last_day = M - p.first;
        auto it = avail.upper_bound(last_day);
        if (it != begin(avail)) {
            --it;
            avail.erase(it);
            res += p.second;
        }
    }
    cout << res << "\n";

    return 0;
}