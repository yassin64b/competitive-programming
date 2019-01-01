#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n, s, l;
    cin >> n >> s >> l;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    deque<int> mn, mx;
    vector<vector<int>> add(n + 1), erase(n + 1);
    multiset<int> cur;
    add[0].push_back(0);
    erase[1].push_back(0);
    for (int i = 0, j = 0; i <= n; ++i) {
        while (j < n && (mn.empty() || (abs(a[j] - mn.front()) <= s && abs(mx.front() - a[j]) <= s))) {
            while (!mn.empty() && mn.back() > a[j]) {
                mn.pop_back();
            }
            mn.push_back(a[j]);
            while (!mx.empty() && mx.back() < a[j]) {
                mx.pop_back();
            }
            mx.push_back(a[j]);
            ++j;
        }

        for (int x : erase[i]) {
            if (cur.find(x) != end(cur)) {
                cur.erase(cur.find(x));
            }
        }
        for (int x : add[i]) {
            cur.insert(x);
        }

        if (i < n) {
            if (!cur.empty()) {
                int mn_cost = *begin(cur);
                if (i + l <= j) {
                    add[i + l].push_back(mn_cost + 1);
                    if (j + 1 <= n) {
                        erase[j + 1].push_back(mn_cost + 1);
                    }
                }
            }
            if (mn.front() == a[i]) {
                mn.pop_front();
            }
            if (mx.front() == a[i]) {
                mx.pop_front();
            }
        }   
    }
    cout << (cur.empty() ? -1 : *begin(cur)) << "\n";

    return 0;
}