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
#include <cassert>

using namespace std;

class TaskC {
public:
    void solve(istream& in, ostream& out) {
        int n, m;
        in >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                in >> a[i][j];
            }
        }
        int k;
        in >> k;
        vector<pair<int,int>> lr(k);
        for (int i = 0; i < k; ++i) {
            in >> lr[i].first >> lr[i].second;
            --lr[i].first;
            --lr[i].second;
        }
        
        vector<int> sorted(n);
        for (int i = 0; i < n; ++i) {
            sorted[i] = i;
        }
        
        //set<pair<int,int>> v;
        for (int j = 0; j < m; ++j) {
            //cout << "row " << j << " : " << endl;
            int mx = a[0][j], start = 0;
            for (int i = 1; i < n; ++i) {
                if (a[i][j] > mx) {
                    mx = a[i][j];
                } else if (a[i][j] < mx) {
                    //cout << mx << " set till " << i-1 << " to " << start << endl;
                    //v.insert(make_pair(start, j-1));
                    for (int kk = start; kk < i; ++kk) {
                        sorted[kk] = min(sorted[kk], start);
                    }
                    start = i;
                    mx = a[i][j];
                }
            }
            //cout << mx << " 2set till " << n-1 << " to " << start << endl;
            for (int kk = start; kk < n; ++kk) {
                sorted[kk] = min(sorted[kk], start);
            }
        }
        
        /*for (int i = 0; i < n; ++i) {
            cout << sorted[i] << endl;
        }*/
        for (int i = 0; i < k; ++i) {
            if (sorted[lr[i].second] <= lr[i].first) {
                out << "Yes\n";
            } else {
                out << "No\n";
            }
        }
    }
};


int main() {
    std::ios::sync_with_stdio(false);

    TaskC solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}