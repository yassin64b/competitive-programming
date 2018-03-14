#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    vector<vector<int>> g(N, vector<int>(N, 10'000'000));
    vector<tuple<int, int, int>> con;
    for (int i = 0; i < M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        con.emplace_back(a - 1, b - 1, c);
        g[a - 1][b - 1] = g[b - 1][a - 1] = c;
    }
    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    for (int i = 0; i < M; ++i) {
        int a, b, c;
        tie(a, b, c) = con[i];
        if (g[a][b] != c) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << N * (N - 1) / 2 << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            cout << i + 1 << " " << j + 1 << " " << g[i][j] << "\n";
        }
    }
    
    return 0;
}