/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author yassin
 */

#include <fstream>

#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#include <tuple>
#include <queue>
#include <functional>
#include <stack>
#include <numeric>
#include <cassert>

using namespace std;

class yandexC {
private:
    int n;
    vector<int> a;
    vector<vector<int>> children;
    
    long long dfs(int u, int flag) {
        long long res = 0;
        
        for (int v : children[u]) {
            res += dfs(v, flag);
        }
        res += flag * res;
        
        return res + a[u];
    }
public:
    void solve(istream& in, ostream& out) {
        in >> n;
        a.resize(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        children.resize(n);
        for (int i = 0; i < n; ++i) {
            int k;
            in >> k;
            children[i].resize(k);
            for (int j = 0; j < k; ++j) {
                in >> children[i][j];
                --children[i][j];
            }
        }
        out << dfs(0, 0) << " " << dfs(0, 1) << "\n";
        
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    yandexC solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}