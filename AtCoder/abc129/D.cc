#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; ++i) {
        cin >> S[i];
    }
    vector<vector<int>> row(H, vector<int>(W, 0));
    vector<vector<int>> col(row);

    for (int i = 0; i < H; ++i) {
        for (int j = 0, k = 0, cnt = 0; j < W; ++j) {  
            if (k <= j) {
                k = j;
                cnt = 0;
                while (k < W && S[i][k] == '.') {
                    ++cnt;
                    ++k;
                }
            }
            row[i][j] = cnt;
        }
    }
    for (int j = 0; j < W; ++j) {
        for (int i = 0, k = 0, cnt = 0; i < H; ++i) {
            if (k <= i) {
                k = i;
                cnt = 0;
                while (k < H && S[k][j] == '.') {
                    ++cnt;
                    ++k;
                }
            }
            col[i][j] = cnt;
        }
    }
    int res = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            res = max(res, row[i][j] + col[i][j] - 1);
        }
    }
    cout << res << "\n";
    
    return 0;
}