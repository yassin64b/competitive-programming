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

class TaskD {
public:
    void solve(istream& in, ostream& out) {
        int N;
        in >> N;
        vector<int> a(3*N);
        for (int i = 0; i < 3*N; ++i) {
            in >> a[i];
        }
        
        vector<long long> mx(3*N, -1), mn(3*N, -1);
        multiset<int> s;
        long long cur_sum = 0;
        for (int i = 0; i < 3*N; ++i) {
            if ((int)s.size() < N) {
                s.insert(a[i]);
                cur_sum += a[i];
            } else {
                if (a[i] > *s.begin()) {
                    cur_sum -= *s.begin();
                    cur_sum += a[i];
                    s.erase(s.begin());
                    s.insert(a[i]);
                }
            }
            mx[i] = cur_sum;
        }
        cur_sum = 0;
        s.clear();
        for (int i = 3*N-1; i >= 0; --i) {
            if ((int)s.size() < N) {
                s.insert(a[i]);
                cur_sum += a[i];
            } else {
                if (a[i] < *s.rbegin()) {
                    cur_sum -= *s.rbegin();
                    cur_sum += a[i];
                    s.erase(--s.end());
                    s.insert(a[i]);
                }
            }
            mn[i] = cur_sum;
        }
        
        long long res = -1000LL * 1000 * 1000 * 1000 * 1000 * 1000;
        for (int i = N-1; i < 2*N; ++i) {
            //cout << "cut after " << i << endl;
            //cout << mx[i] << " " << mn[i + 1] << endl;
            res = max(res, mx[i] - mn[i + 1]);
        }
        
        out << res << "\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    TaskD solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}