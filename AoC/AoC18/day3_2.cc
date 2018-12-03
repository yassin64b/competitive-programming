#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    string s;
    vector<vector<int>> grid(1'001, vector<int>(1'001, 0));
    vector<tuple<int, int, int, int, int>> claim;
    while (getline(cin, s)) {
        stringstream ss(s);
        char delim;
        int id, x, y, n, m; 
        ss >> delim >> id >> delim >> x >> delim >> y >> delim;
        ss >> n >> delim >> m;
        claim.emplace_back(id, x, y, n, m);
        for (int i = x; i < x + n; ++i) {
            for (int j = y; j < y + m; ++j) {
                ++grid[i][j];
            }
        }
    }
    for (auto [id, x, y, n, m] : claim) {
        bool ok = true;
        for (int i = x; i < x + n; ++i) {
            for (int j = y; j < y + m; ++j) {
                if (grid[i][j] != 1) {
                    ok = false;
                }
            }
        }
        if (ok) {
            cout << id << endl;
            return 0;
        }
    }
    
    return 0;
}
