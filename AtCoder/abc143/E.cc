#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int N, M, L;
    cin >> N >> M >> L;
    vector<vector<pair<int, int>>> g(N);
    for (int i = 0; i < M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a - 1].emplace_back(b - 1, c);
        g[b - 1].emplace_back(a - 1, c);
    }
    vector<vector<int>> mn(N, vector<int>(N, -1));
    for (int u = 0; u < N; ++u) {
        vector<vector<int>> mx(N, vector<int>(N + 1, -1));
        priority_queue<pair<int, int>> pq;
        mx[u][0] = L;
        pq.emplace(L, u);
        for (int i = 0; i < N; ++i) {
            for (int v = 0; v < N; ++v) {
                if (mx[v][i] >= 0) {
                    mx[v][i + 1] = L + 1;
                }
            }
            priority_queue<pair<int, int>> nxt;
            while (!pq.empty()) {
                auto tmp = pq.top();
                int left = tmp.first, v = tmp.second;
                pq.pop();
                if (mx[v][i] > left) continue;
                for (auto tmp : g[v]) {
                    int w = tmp.first, c = tmp.second;
                    if (left - c > mx[w][i]) {
                        mx[w][i] = left - c;
                        mx[w][i + 1] = L + 1;
                        pq.emplace(mx[w][i], w);
                    } else if (left - c < 0 && L - c > mx[w][i + 1]) {
                        mx[w][i + 1] = L - c;
                        nxt.emplace(mx[w][i + 1], w);
                    }
                }
            }
            pq = nxt;
        }
        for (int v = 0; v < N; ++v) {
            for (int j = 0; j <= N; ++j) {
                if (mx[v][j] != -1) {
                    mn[u][v] = j;
                    break;
                }
            }
        }
    }

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int s, t;
        cin >> s >> t;
        --s;
        --t;
        cout << mn[s][t] << "\n";
    }
    return 0;
}