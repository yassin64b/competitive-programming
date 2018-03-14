#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool dfs(int u1, const vector<vector<int>> &g1, int u2, const vector<vector<int>> &g2) {
    if (g1[u1].size() != g2[u2].size()) {
        return false;
    } else if (g1[u1].size() == 1U) {
        return dfs(g1[u1][0], g1, g2[u2][0], g2);   
    } else if (g1[u1].empty()) {
        return true;
    }
    return (dfs(g1[u1][0], g1, g2[u2][0], g2) && dfs(g1[u1][1], g1, g2[u2][1], g2))
            || (dfs(g1[u1][0], g1, g2[u2][1], g2) && dfs(g1[u1][1], g1, g2[u2][0], g2));
}
int main() 
{
    ios::sync_with_stdio(false);
    
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        int n;
        cin >> n;
        vector<int> p1(n), p2(n);
        vector<vector<int>> g1(n), g2(n);
        int r1 = -1, r2 = -1;
        for (int i = 0; i < n; ++i) {
            cin >> p1[i];
            if (--p1[i] != -1) {
                g1[p1[i]].push_back(i);
            } else {
                r1 = i;
            }
        }
        for (int i = 0; i < n; ++i) {
            cin >> p2[i];
            if (--p2[i] != -1) {
                g2[p2[i]].push_back(i);
            } else {
                r2 = i;
            }
        }
        cout << dfs(r1, g1, r2, g2) << "\n";
    }
    
    return 0;
}