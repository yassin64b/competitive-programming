#include <bits/stdc++.h>

using namespace std;

class ChangeDistances {
public:
    vector <string> findGraph(vector <string>);
};

vector <string> ChangeDistances::findGraph(vector <string> g) {
    int n = g.size();
    vector<string> h(n, string(n, '0'));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (g[i][j] == '0' && i != j) h[i][j] = '1';
        }
    }
    return h;
}