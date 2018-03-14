#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> g(N);
        for (int i = 0; i < M; ++i) {
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        set<int> even_deg, odd_deg;
        for (int i = 0; i < N; ++i) {
            if (g[i].size() % 2 == 1)
                odd_deg.insert(i);
            else
                even_deg.insert(i);
        }
        while (true) {
            if (even_deg.empty()) {
                cout << 0 << endl;
                break;
            }
            int u = *even_deg.begin();
            for (int v : g[u]) {
                if (even_deg.find(v) != even_deg.end()) {
                    even_deg.erase(v);
                    odd_deg.insert(v);
                } else if (odd_deg.find(v) != odd_deg.end()) {
                    odd_deg.erase(v);
                    even_deg.insert(v);
                }
            }
            even_deg.erase(u);
            
            if (even_deg.empty()) {
                cout << 1 << endl;
                break;
            }
            u = *even_deg.begin();
            for (int v : g[u]) {
                if (even_deg.find(v) != even_deg.end()) {
                    even_deg.erase(v);
                    odd_deg.insert(v);
                } else if (odd_deg.find(v) != odd_deg.end()) {
                    odd_deg.erase(v);
                    even_deg.insert(v);
                }
            }
            even_deg.erase(u);
        }
    }
    
    return 0;
}