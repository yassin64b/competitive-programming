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

class Revmatching {
private:
int N;

int backtrack(int i, vector<int> &nodes, const vector<vector<pair<int,int>>>& g) {
    int ret = 0;
    if (i == N) {
        if (nodes.empty()) {
            return 1000*1000*1000;
        }
        int sz = nodes.size();
        vector<int> cost(2*N, 0);
        for (int j = 0; j < sz; ++j) {
            for (auto &p : g[nodes[j]]) {
                int c = p.first, v = p.second;
                cost[v] += c;
            }
        }
        int szN = 0;
        for (int j = 0; j < 2*N; ++j) {
            szN += cost[j] > 0;
        }
        sort(cost.begin(), cost.end());
        int cost1 = 0;
        //cout << "delete: ";
        for (int j = 0, cnt = 0; cnt < szN-sz+1; ++j) {
            cost1 += cost[j];
            //f (cost[j]) cout << j << " ";
            if (cost[j]) ++cnt;
        }
        //cout << "for cost " << cost1 << endl;
        
        cost.assign(2*N, 0);
        for (int j = 0; j < sz; ++j) {
            for (auto &p : g[nodes[j]+N]) {
                int v = p.second, c = p.first;
                cost[v] += c;
            }
        }
        szN = 0;
        for (int j = 0; j < 2*N; ++j) {
            szN += cost[j] > 0;
        }
        sort(cost.begin(), cost.end());
        int cost2 = 0;
        //cout << "delete: ";
        for (int j = 0, cnt = 0; cnt < szN-sz+1; ++j) {
            cost2 += cost[j];
            //if (cost[j]) cout << j << " ";
            if (cost[j]) ++cnt;
        }
        //cout << "for cost " << cost1 << endl;
        
        return min(cost1, cost2);
    } 
    ret = backtrack(i+1, nodes, g);
    nodes.push_back(i);
    ret = min(ret, backtrack(i+1, nodes, g));
    nodes.pop_back();
    return ret;
}
public:
    int smallest(vector <string>);
};

int Revmatching::smallest(vector <string> A) {
    N = A.size();
    vector<vector<pair<int,int>>> g(2*N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (A[i][j] != '0') {
                g[i].emplace_back(A[i][j]-'0', j+N);
                g[j+N].emplace_back(A[i][j]-'0', i);
            }
        }
    }

    vector<int> nodes;
    return backtrack(0, nodes, g);
}