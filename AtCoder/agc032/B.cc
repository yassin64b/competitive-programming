#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int N;
    cin >> N;

    vector<pair<int, int>> e;
    if (N % 2 == 1) {
        e.emplace_back(1, N);
        e.emplace_back(N, N - 1);
        for (int i = 2; i <= N / 2; ++i) {
            for (int j = 1; j < i; ++j) {
                e.emplace_back(i, j);
                e.emplace_back(N - i, j);
            }
            for (int j = N - i + 1; j <= N; ++j) {
                e.emplace_back(N - i, j);
                e.emplace_back(i, j);
            }
        }
    } else {
        e.emplace_back(1, 2);
        e.emplace_back(1, N - 1);
        e.emplace_back(2, N);
        e.emplace_back(N - 1, N);
        for (int i = 3; i <= N / 2; ++i) {
            for (int j = 1; j < i; ++j) {
                e.emplace_back(i, j);
                e.emplace_back(N - i + 1, j);
            }
            for (int j = N - i + 2; j <= N; ++j) {
                e.emplace_back(N - i + 1, j);
                e.emplace_back(i, j);
            }
        }
    }


    cout << e.size() << "\n";
    for (const auto &p : e) {
        cout << p.first << " " << p.second << "\n";
    }



    return 0;
}