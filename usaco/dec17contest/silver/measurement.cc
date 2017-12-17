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

class measurement {
public:
    void solve(istream& in, ostream& out) {
        int N, G;
        in >> N >> G;
        vector<tuple<int, int, int>> meas(N);
        for (int i = 0; i < N; ++i)
            in >> get<0>(meas[i]) >> get<1>(meas[i]) >> get<2>(meas[i]);
        sort(meas.begin(), meas.end());
    
        const int def = G;
        map<int, set<int>> valcow;
        map<int, int> cowval;
        for (int i = 0; i < N; ++i) {
            valcow[def].insert(get<1>(meas[i]));
            cowval[get<1>(meas[i])] = def;
        }
        valcow[def].insert(0); //all other cows
    
        int res = 0;
        for (int i = 0; i < N; ++i) {
            int day, change, cow_id;
            tie(day, cow_id, change) = meas[i];
        
            set<int> mxs = valcow.rbegin()->second;
        
            valcow[cowval[cow_id]].erase(cow_id);
            if (valcow[cowval[cow_id]].empty())
                valcow.erase(cowval[cow_id]);
        
            cowval[cow_id] += change;
            valcow[cowval[cow_id]].insert(cow_id);
        
            if (mxs != valcow.rbegin()->second)
                ++res;
        }
        out << res << "\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    measurement solver;
    std::ifstream in("measurement.in");
    std::ofstream out("measurement.out");
    solver.solve(in, out);
    return 0;
}
