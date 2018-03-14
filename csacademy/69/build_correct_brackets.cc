#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cassert>
#include <map>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    
    string s;
    cin >> s;
    int n = s.size();
    constexpr int MOD = 1000000007, INF = 2501;
    vector<vector<int>> min_cost(n + 1, vector<int>(n + 1, INF)), num_ways(n + 1, vector<int>(n + 1, 0));
    num_ways[0][0] = 1;
    min_cost[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= i; ++j) { // s[i] should be ')'
            int cost = (s[i] == '(');
            if (min_cost[i][j] + cost < min_cost[i + 1][j - 1]) {
                min_cost[i + 1][j - 1] = min_cost[i][j] + cost;
                num_ways[i + 1][j - 1] = num_ways[i][j];
            } else if (min_cost[i][j] + cost == min_cost[i + 1][j - 1]) {
                num_ways[i + 1][j - 1] += num_ways[i][j];
                num_ways[i + 1][j - 1] %= MOD;
            }
        }
        for (int j = 0; j <= i; ++j) { // s[i] should be '('
            int cost = (s[i] == ')');
            if (min_cost[i][j] + cost < min_cost[i + 1][j + 1]) {
                min_cost[i + 1][j + 1] = min_cost[i][j] + cost;
                num_ways[i + 1][j + 1] = num_ways[i][j];
            } else if (min_cost[i][j] + cost == min_cost[i + 1][j + 1]) {
                num_ways[i + 1][j + 1] += num_ways[i][j];
                num_ways[i + 1][j + 1] %= MOD;
            }
        }
    }
    cout << min_cost[n][0] << " " << num_ways[n][0] << endl;
    
    return 0;
}