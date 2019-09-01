#include <bits/stdc++.h>

using namespace std;

void go(int cx, int cy, const vector<pair<int, int>> &xy,
        const vector<int> &taken, double &res) {
    double cur = sqrt(1LL * cx * cx + 1LL * cy * cy);
    res = max(res, cur);
    for (int i = 0; i < (int)xy.size(); ++i) {
        if (!taken[i]) {
            int nx = cx + xy[i].first, ny = cy + xy[i].second;
            double ncur = sqrt(1LL * nx * nx + 1LL * ny * ny);
            if (ncur > cur) {
                cx = nx;
                cy = ny;
                cur = ncur;
                res = max(res, cur);
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    auto now = chrono::system_clock::now();
    auto now_ms = chrono::time_point_cast<chrono::milliseconds>(now);
    auto epoch = now_ms.time_since_epoch();
    auto value = chrono::duration_cast<chrono::milliseconds>(epoch);
    mt19937 gen(value.count());

    int N;
    cin >> N;
    vector<pair<int, int>> xy(N);
    for (int i = 0; i < N; ++i) {
        cin >> xy[i].first >> xy[i].second;
    }
    double res = 0;
    for (int r = 0; r < 2000; ++r) {
        vector<int> taken(N, 0);
        for (int i = 0; i < N; ++i) {
            taken[i] = 1;
            go(xy[i].first, xy[i].second, xy, taken, res);
            taken[i] = 0;
        }
        shuffle(begin(xy), end(xy), gen);
    }
    cout.precision(17);
    cout << fixed << res << "\n";

    return 0;
}