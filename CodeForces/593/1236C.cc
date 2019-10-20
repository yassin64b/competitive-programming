#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n;
    cin >> n;
    int goal = n * n / 2;
    vector<vector<int>> g(n);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j <= n * n; j += 2 * n) {
            g[i].push_back(j);
        }
        for (int j = 2 * n - i; j <= n * n; j += 2 * n) {
            g[i].push_back(j);
        }
        sort(begin(g[i]), end(g[i]));
        for (int x : g[i]) {
            cout << x << " ";
        }
        cout << "\n";
    }

    /*for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            int cnt = 0;
            for (int x : g[i]) {
                for (int y : g[j]) {
                    assert(x != y);
                    cnt += x > y;
                }
            }
            //cout << cnt << " " << goal << endl;
            assert(cnt >= goal);
        }
    }*/

    return 0;
}