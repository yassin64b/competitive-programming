#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void dijkstra(int start, const vector<vector<int>>& D, const vector<int>& E, 
              const vector<int>& S, vector<double>& time, int N) {
    priority_queue<pair<double, int>> pq;
    pq.emplace(-0, start);
    while (!pq.empty()) {
        double cur_dist = -pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (cur_dist / S[start] > time[u]) {
            continue;
        }
        for (int v = 0; v < N; ++v) {
            if (D[u][v] != -1 && cur_dist + D[u][v] <= E[start] && (cur_dist + D[u][v]) / S[start] < time[v]) {
                pq.emplace(-(cur_dist + D[u][v]), v);
                time[v] = (cur_dist + D[u][v]) / S[start];
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int N, Q;
        cin >> N >> Q;
        vector<int> E(N), S(N);
        for (int i = 0; i < N; ++i) {
            cin >> E[i] >> S[i];
        }
        vector<vector<int>> D(N, vector<int>(N));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> D[i][j];
            }
        }

        vector<vector<double>> time(N, vector<double>(N, 1e18));
        for (int i = 0; i < N; ++i) {
            dijkstra(i, D, E, S, time[i], N);
        }

        for (int k = 0; k < N; ++k) {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    time[i][j] = min(time[i][j], time[i][k] + time[k][j]);
                }
            }
        }

        cout << "Case #" << t << ": ";
        for (int q = 0; q < Q; ++q) {
            int U, V;
            cin >> U >> V;
            --U; --V;

            cout.precision(17);
            cout << fixed << time[U][V] << (q == Q-1 ? "\n" : " ");
        }
    }
}