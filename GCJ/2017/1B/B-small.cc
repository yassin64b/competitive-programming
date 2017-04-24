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

class gcj_17_1B_B {
public:
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        for (int t = 1; t <= T; ++t) {
            int N, R, O, Y, G, B, V;
            in >> N >> R >> O >> Y >> G >> B >> V;
            vector<pair<int, char>> v{{R, 'R'}, {O, 'O'}, {Y, 'Y'}, {G, 'G'}, {B, 'B'}, {V, 'V'}};
            
            string res;
            for (int i = 0; i < N; ) {
                sort(v.begin(), v.end(), greater<pair<int, char>>());
                if (v[0].first > max(v[1].first, v[2].first)) {
                    res += v[0].second;
                    res += v[1].second;
                    --v[0].first;
                    --v[1].first;
                    i += 2;
                } else {
                    for (int k = 2; k >= 0; --k) {
                        if (v[k].first) {
                            for (int j = 0; j <= k; ++j) {
                                res += v[j].second;
                                --v[j].first;
                            }
                            i += k + 1;
                            break;
                        }
                    }
                }
            }
            //cout << res << endl;
            out << "Case #" << t << ": ";
            for (int i = 0; i < N; ++i) {
                if (res[i] == res[(i+1)%N]) {
                    goto next_test;
                }
            }
            goto passed;
            next_test:;
            swap(res[N-1], res[N-2]);
            for (int i = 0; i < N; ++i) {
                if (res[i] == res[(i+1)%N]) {
                    out << "IMPOSSIBLE\n";
                    goto next_case;
                }
            }
            passed:;
            for (int i = 0; i < (int)v.size(); ++i) {
                if (v[i].first != 0) {
                    out << "IMPOSSIBLE\n";
                    goto next_case;
                }
            }
            assert(count(res.begin(), res.end(), 'R') == R);
            assert(count(res.begin(), res.end(), 'O') == O);
            assert(count(res.begin(), res.end(), 'Y') == Y);
            assert(count(res.begin(), res.end(), 'G') == G);
            assert(count(res.begin(), res.end(), 'B') == B);
            assert(count(res.begin(), res.end(), 'V') == V);
            out << res << "\n";
            next_case:;
        }
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    gcj_17_1B_B solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}