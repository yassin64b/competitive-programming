#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> u(n);
    for (int i = 0; i < n; ++i) {
        cin >> u[i];
    }
    constexpr int MX = 100'000;
    vector<vector<int>> cnt(MX + 1);
    set<int> cnts; // 
    vector<int> val(MX + 1, 0);
    int res = 0;
    for (int i = 0; i < n; ++i) {
        int prev = cnt[u[i]].size();
        if (--val[prev] == 0) {
            cnts.erase(prev);
        }

        cnt[u[i]].push_back(i);
        int nxt = prev + 1;
        ++val[nxt];
        cnts.insert(nxt);

        if (cnts.size() == 2) {
            int a = *cnts.begin();
            int b = *++cnts.begin();
            int numa = val[a], numb = val[b];
            if (a == b + 1 && numa == 1 || b == a + 1 && numb == 1
                || a == 1 && numa == 1 || b == 1 && numb == 1) {
                res = i + 1;
            }
        } else if (cnts.size() == 1) {
            int a = *cnts.begin();
            int numa = val[a];
            if (numa == 1 || numa == i + 1) {
                res = i + 1;
            }
        }
    }
    cout << res << "\n";

    return 0;
}