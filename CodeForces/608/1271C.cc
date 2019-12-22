#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n, sx, sy;
    cin >> n >> sx >> sy;
    vector<pair<int, int>> xy(n);
    for (int i = 0; i < n; ++i) {
        cin >> xy[i].first >> xy[i].second;
    }
    int cnt_greater_sx = 0, cnt_smaller_sx = 0;
    int cnt_greater_sy = 0, cnt_smaller_sy = 0;
    for (int i = 0; i < n; ++i) {
        cnt_greater_sx += xy[i].first > sx;
        cnt_smaller_sx += xy[i].first < sx;
        cnt_greater_sy += xy[i].second > sy;
        cnt_smaller_sy += xy[i].second < sy;
    }
    int mx = max(cnt_greater_sy, max(cnt_smaller_sy,
                        max(cnt_greater_sx, cnt_smaller_sx)));
    cout << mx << "\n";
    if (cnt_greater_sx == mx) {
        cout << sx + 1 << " " << sy << "\n";
    } else if (cnt_smaller_sx == mx) {
        cout << sx - 1 << " " << sy << "\n";
    } else if (cnt_greater_sy == mx) {
        cout << sx << " " << sy + 1 << "\n";
    } else {
        cout << sx << " " << sy - 1 << "\n";
    }

    return 0;
}