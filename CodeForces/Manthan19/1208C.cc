#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> bb{{8, 9, 1, 13},
                            {3, 12, 7, 5},
                            {0, 2, 4, 11},
                            {6, 10, 15, 14}};
    vector<vector<int>> res(n, vector<int>(n));
    int mask = 0;
    for (int i = 0; i < n; i += 4) {
        for (int j = 0; j < n; j += 4) {
            for (int x = 0; x < 4; ++x) {
                for (int y = 0; y < 4; ++y) {
                    res[i+x][j+y] = bb[x][y] + (mask << 4);
                }
            }
            ++mask;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}