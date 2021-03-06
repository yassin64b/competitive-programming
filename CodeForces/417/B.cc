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

class TaskB {
private:
    int n, m;
    long long brute(int i, int j, const vector<pair<int, int>>& lf) {
        long long cost = 0;
        bool up = false;
        for (int x = i + 1; x < n; ++x) {
            if (lf[x].first != 0 || lf[x].second != m + 1) {
                up = true;
            }
        }
        if (up) {
            if (j == 0) {
                cost = 2 * lf[i].first + brute(i + 1, 0, lf) + up;
                //cout << cost << endl;
                cost = min(cost, m + 1 + brute(i + 1, m + 1, lf) + up);
                //cout << cost << endl;
            } else {
                assert(j == m + 1);
                cost = 2 * (m + 1 - lf[i].second) + brute(i + 1, m + 1, lf) + up;
                //cout << cost << endl;
                cost = min(cost, m + 1 + brute(i + 1, 0, lf) + up);
                //cout << cost << endl;
            }
            //cout << i << " " << j << " -> " << cost << endl;
        } else {
            if (j == 0) {
                cost = lf[i].first;
            } else {
                assert(j == m + 1);
                cost = m + 1 - lf[i].second;
            }
            //cout << "up " << j << " -> " << cost << endl;
        }
        return cost;
    }
public:
    void solve(istream& in, ostream& out) {
        in >> n >> m;
        vector<pair<int, int>> lf(n, {0, m + 1});
        vector<string> b(n);
        for (int i = 0; i < n; ++i) {
            in >> b[i];
            for (int j = 0; j < m + 2; ++j) {
                if (b[i][j] == '1') {
                    lf[i].first = j;
                }
            }
            for (int j = m + 1; j >= 0; --j) {
                if (b[i][j] == '1') {
                    lf[i].second = j;
                }
            }
        }
        reverse(lf.begin(), lf.end());
        
        out << brute(0, 0, lf) << "\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    TaskB solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
