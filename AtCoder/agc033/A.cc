#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int H, W;
    cin >> H >> W;
    vector<string> A(H);
    constexpr int INF = 1'000'000;
    vector<vector<int>> dist(H, vector<int>(W, INF));
    queue<pair<int, int>> q;
    for (int i = 0; i < H; ++i) {
        cin >> A[i];
        for (int j = 0; j < W; ++j) {
            if (A[i][j] == '#') {
                dist[i][j] = 0;
                q.emplace(i, j);
            }
        }
    }
    int dx[]{1, -1, 0, 0};
    int dy[]{0, 0, 1, -1};
    while (!q.empty()) {
        int i = q.front().first, j = q.front().second;
        q.pop();
        for (int k = 0; k < 4; ++k) {
            int ni = i + dx[k], nj = j + dy[k];
            if (ni >= 0 && ni < H && nj >= 0 && nj < W) {
                if (dist[i][j] + 1 < dist[ni][nj]) {
                    q.emplace(ni, nj);
                    dist[ni][nj] = dist[i][j] + 1;
                }
            }
        }
    }
    int res = 0;
    for (int i = 0; i < H; ++i) {
        res = max(res, *max_element(begin(dist[i]), end(dist[i])));
    }
    cout << res << "\n";

    return 0;
}