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

constexpr int INF = 1000 * 1000 * 1000 + 1;
class hayfeast {
public:
    void solve(istream& in, ostream& out) {
        int N;
        long long M;
        in >> N >> M;
        vector<pair<int, int>> haybales(N);
        for (int i = 0; i < N; ++i)
            in >> haybales[i].first >> haybales[i].second;
        int mn = INF;
        multiset<int> cur_spices;
        long long cur_flavor = 0;
        int i = 0, j = 0;
        while (j < N) {
            cur_flavor += haybales[j].first;
            cur_spices.insert(haybales[j].second);
            while (cur_flavor >= M) {
                int cur_spiciness = *cur_spices.rbegin();
                mn = min(mn, cur_spiciness);
                cur_spices.erase(cur_spices.find(haybales[i].second));
                cur_flavor -= haybales[i].first;
                ++i;
            }
            ++j;
        }
        out << mn << "\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    hayfeast solver;
    std::ifstream in("hayfeast.in");
    std::ofstream out("hayfeast.out");
    solver.solve(in, out);
    return 0;
}
