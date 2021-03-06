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

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

class TaskB {
public:
    void solve(istream& in, ostream& out) {
        int n;
        string s;
        in >> n >> s;
        
        tuple<int,int,int> cnt{0, 0, 0};
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'B') ++get<0>(cnt);
            else if (s[i] == 'G') ++get<1>(cnt);
            else if (s[i] == 'R') ++get<2>(cnt);
        }
        
        string res;
        stack<tuple<int,int,int>> st;
        vvvi vis(201, vvi(201, vi(201, 0)));
        
        st.push(cnt);
        vector<int> can{0, 0, 0};
        while (!st.empty() && !(can[0] && can[1] && can[2])) {
            tuple<int,int,int> v = st.top();
            st.pop();
            if (vis[get<0>(v)][get<1>(v)][get<2>(v)]) {
                continue;
            }
            vis[get<0>(v)][get<1>(v)][get<2>(v)] = 1;
            
            if (get<0>(v) + get<1>(v) + get<2>(v) == 1) {
                can[0] = can[0] || get<0>(v);
                can[1] = can[1] || get<1>(v);
                can[2] = can[2] || get<2>(v);
            }
                
            if (get<0>(v) >= 2) st.push(make_tuple(get<0>(v)-1, get<1>(v), get<2>(v)));
            if (get<1>(v) >= 2) st.push(make_tuple(get<0>(v), get<1>(v)-1, get<2>(v)));
            if (get<2>(v) >= 2) st.push(make_tuple(get<0>(v), get<1>(v), get<2>(v)-1));
            
            if (get<0>(v) && get<1>(v)) st.push(make_tuple(get<0>(v)-1, get<1>(v)-1, get<2>(v)+1));
            if (get<0>(v) && get<2>(v)) st.push(make_tuple(get<0>(v)-1, get<1>(v)+1, get<2>(v)-1));
            if (get<1>(v) && get<2>(v)) st.push(make_tuple(get<0>(v)+1, get<1>(v)-1, get<2>(v)-1));
        }
        
        out << (can[0] ? "B" : "") << (can[1] ? "G" : "") << (can[2] ? "R" : "") << endl;
    }
};


int main() {
    std::ios::sync_with_stdio(false);

    TaskB solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
