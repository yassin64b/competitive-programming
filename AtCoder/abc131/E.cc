#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    if (K > (N - 1) * (N - 2) / 2) {
        cout << "-1\n";
        return 0;
    }
    vector<pair<int, int>> e;
    for (int i = 2; i <= N; ++i) {
        e.emplace_back(1, i);
    }
    int curk = (N - 1) * (N - 2) / 2;
    for (int u = 2; curk > K && u <= N; ++u) {
        for (int v = u + 1; curk > K && v <= N; ++v) {
            e.emplace_back(u, v);
            --curk;
        }
    }
    cout << e.size() << "\n";
    for (const auto &p : e) {
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}