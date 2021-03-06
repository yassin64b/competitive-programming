/*
ID: yassin.2
PROG: sort3
LANG: C++11
*/
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

class sort3 {
public:
    void solve(istream& in, ostream& out) {
        int N;
        in >> N;
        vector<int> v(N);
        int cnt[4] = {};
        for (int i = 0; i < N; ++i) {
            in >> v[i];
            ++cnt[v[i]];
        }
        cnt[2] += cnt[1];
        cnt[3] += cnt[2];
        vector<int> vv(N);
        for (int i = 0; i < N; ++i) {
            for (int j = 1; j <= 3; ++j) {
                if (i < cnt[j]) {
                    vv[i] = j;
                    break;
                }
            }
        }
        
        int res = 0;
        for (int i = 0; i < N; ++i) {
            if (v[i] != vv[i]) {
                bool found = false;
                for (int j = i + 1; !found && j < N; ++j) {
                    if (v[j] != vv[j] && v[j] == vv[i] && v[i] == vv[j]) {
                        swap(v[i], v[j]);
                        found = true;
                    }
                }
                for (int j = i + 1; !found && j < N; ++j) {
                    if (v[j] != vv[j] && v[j] == vv[i]) {
                        swap(v[i], v[j]);
                        found = true;
                    }
                }
                res += found;
            }
        }
        out << res << "\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    sort3 solver;
    std::ifstream in("sort3.in");
    std::ofstream out("sort3.out");
    solver.solve(in, out);
    return 0;
}
