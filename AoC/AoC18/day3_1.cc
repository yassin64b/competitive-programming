#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    string s;
    vector<vector<int>> grid(1'001, vector<int>(1'001, 0));
    int res = 0;
    while (getline(cin, s)) {
        stringstream ss(s);
        char delim;
        int id, x, y, n, m; 
        ss >> delim >> id >> delim >> x >> delim >> y >> delim;
        ss >> n >> delim >> m;
        for (int i = x; i < x + n; ++i) {
            for (int j = y; j < y + m; ++j) {
                res += (++grid[i][j] == 2);
            }
        }
    }
    cout << res << "\n";
    
    return 0;
}
