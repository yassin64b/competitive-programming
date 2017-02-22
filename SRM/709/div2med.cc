#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

class Permatchd2 {
public:
    int fix(vector <string>);
};
pair<int,int> dfs(int u, vector<string> &graph, vector<int> &vis) {
    vis[u] = 1;
    pair<int,int> res = {1, 0};
    for (int v = 0; v < (int)graph[u].size(); ++v) {
        if (graph[u][v] == 'Y' && !vis[v]) {
            pair<int,int> tmp = dfs(v, graph, vis);
            res.first += tmp.first;
            res.second += tmp.second + 1;
        } else if (graph[u][v] == 'Y' && vis[v]) {
            res.second += 1;
        }
    }
    return res;
}

int Permatchd2::fix(vector <string> graph) {
    int n = graph.size();
    vector<int> vis(n, 0);
    vector<pair<int,int>> comp;
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            pair<int,int> tmp = dfs(i, graph, vis);
            tmp.second /= 2;
            comp.push_back(tmp);
            cout << tmp.first << " " << tmp.second << endl;
        }
    }
    int num_odd = 0;
    for (int i = 0; i < (int)comp.size(); ++i) {
        num_odd += comp[i].second % 2;
    }
    
    if (comp[0].second == n * (n-1) / 2 && comp[0].second % 2 == 1) return -1;
    return num_odd; //just connect all odd components in a circle -> even component
}

//Powered by [KawigiEdit] 2.0!