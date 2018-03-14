#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct city {
    int s, x, y;    
};

constexpr int MAXV = 1000;

inline int man_dist(const city &a, const city &b) {
    return (a.x - b.x < 0 ? b.x - a.x : a.x - b.x) + (a.y - b.y < 0 ? b.y - a.y : a.y - b.y);
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, T;
    cin >> N >> T;
    vector<city> v(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i].s >> v[i].x >> v[i].y;
    }
    vector<vector<int>> dist(N, vector<int>(N, 1000*1000));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            dist[i][j] = man_dist(v[i], v[j]);
            if (v[i].s && v[j].s) {
                dist[i][j] = min(dist[i][j], T);
            }
        }
    }
    for (int k = 0; k < N; ++k) {
        if (!v[k].s) continue;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    
    int Q;
    cin >> Q;
    for (int q = 0; q < Q; ++q) {
        int A, B;
        cin >> A >> B;
        cout << dist[A-1][B-1] << "\n";
    }
    
    return 0;
}