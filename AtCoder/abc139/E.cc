#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<vector<int>> A(N, vector<int>(N - 1));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N - 1; ++j) {
            cin >> A[i][j];
            --A[i][j];
        }
    }
    queue<tuple<int, int, int>> q_ready;
    vector<int> in_q(N, 0);
    for (int i = 0; i < N; ++i) {
        int u = i, v = A[i][0];
        if (u == A[v][0] && !in_q[u] && !in_q[v]) {
            q_ready.emplace(u, v, 1);
            in_q[u] = in_q[v] = 1;
        }
    }
    vector<int> cur_ind(N, 0);
    int day = 1;
    for (int i = 0; i < N * (N - 1) / 2; ++i) {
        if (q_ready.empty()) {
            cout << -1 << "\n";
            return 0;
        }
        int u, v, d;
        tie(u, v, d) = q_ready.front();
        q_ready.pop();
        in_q[u] = in_q[v] = 0;
        day = max(day, d);
        ++cur_ind[u];
        ++cur_ind[v];
        if (cur_ind[u] < N - 1) {
            int w = A[u][cur_ind[u]];
            if (u == A[w][cur_ind[w]] && !in_q[u] && !in_q[w]) {
                q_ready.emplace(u, w, d + 1);
                in_q[u] = in_q[w] = 1;
            }
        }
        if (cur_ind[v] < N - 1) {
            int w = A[v][cur_ind[v]];
            if (v == A[w][cur_ind[w]] && !in_q[v] && !in_q[w]) {
                q_ready.emplace(v, w, d + 1);
                in_q[v] = in_q[w] = 1;
            }
        }
    }
    cout << day << "\n";

    return 0;
}