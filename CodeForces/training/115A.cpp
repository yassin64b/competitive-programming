#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <ctime>

using namespace std;

int dfs(int i, vector<int> &p, vector<int> &depth) 
{
    if (depth[i] >= 0) {
        return depth[i];
    } 
    if (p[i] < 0) {
        depth[i] = 1;
    } else {
        depth[i] = dfs(p[i], p, depth) + 1;
    }
    return depth[i];
}

int main()
{
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        --p[i];
    }

    vector<int> depth(n, -1);
    int longestpath = 0;
    for (int i = 0; i < n; ++i) {
        int path = dfs(i, p, depth);
        longestpath = max(longestpath, path);
    }
    cout << longestpath << endl;

    return 0;
}