#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> xy(k);
    set<int> two, one;
    int cnt_zero = 0;
    vector<vector<int>> s(n + 1);
    for (int i = 0; i < k; ++i) {
        cin >> xy[i].first >> xy[i].second;
        s[xy[i].first].push_back(i);
        s[xy[i].second].push_back(i);
        two.insert(i);
    }
    while (!two.empty()) {
        int i = *two.begin();
        two.erase(two.begin());
        int a = xy[i].first, b = xy[i].second;
        for (int j : s[a]) {
            if (two.count(j)) {
                two.erase(j);
                one.insert(j);
            } else if (one.count(j)) {
                one.erase(j);
                ++cnt_zero;
            }
        }
        s[a].clear();
        for (int j : s[b]) {
            if (two.count(j)) {
                two.erase(j);
                one.insert(j);
            } else if (one.count(j)) {
                one.erase(j);
                ++cnt_zero;
            }
        }
        s[b].clear();
        while (!one.empty()) {
            int i = *one.begin();
            one.erase(one.begin());
            int a = xy[i].first, b = xy[i].second;
            for (int j : s[a]) {
                if (two.count(j)) {
                    two.erase(j);
                    one.insert(j);
                } else if (one.count(j)) {
                    one.erase(j);
                    ++cnt_zero;
                }
            }
            s[a].clear();
            for (int j : s[b]) {
                if (two.count(j)) {
                    two.erase(j);
                    one.insert(j);
                } else if (one.count(j)) {
                    one.erase(j);
                    ++cnt_zero;
                }
            }
            s[b].clear();
        }
    }
    cout << cnt_zero << "\n";


    return 0;
}