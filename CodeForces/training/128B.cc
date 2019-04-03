#include <bits/stdc++.h>

using namespace std;
using psi = pair<string, int>;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    string s;
    int k;
    cin >> s >> k;
    const int n = s.size();
    if (k > 1LL * n * (n + 1) / 2) {
        cout << "No such line.\n";
        return 0;
    }

    priority_queue<psi, vector<psi>, greater<psi>> pq;
    for (int i = 0; i < n; ++i) {
        pq.emplace(""s + s[i], i);
    }
    string cur_s;
    cur_s.reserve(n);
    while (!pq.empty()) {
        cur_s = pq.top().first;
        int i = pq.top().second;
        pq.pop();
        if (--k == 0) {
            cout << cur_s << "\n";
            return 0;
        }
        if (i < n - 1) {
            cur_s += s[i + 1];
            pq.emplace(cur_s, i + 1);
        }
    }

    return 0;
}