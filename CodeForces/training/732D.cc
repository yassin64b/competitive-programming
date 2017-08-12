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

class D732 {
public:
    void solve(istream& in, ostream& out) {
        int n, m;
        in >> n >> m;
        vector<int> d(n), a(m + 1);
        vector<vector<int>> exam(m + 1);
        for (int i = 0; i < n; ++i) {
            in >> d[i];
            exam[d[i]].push_back(i);
        }
        for (int i = 1; i <= m; ++i) {
            in >> a[i];
        }
        
        for (int i = 1; i <= m; ++i) {
            if (exam[i].size() == 0) {
                out << -1 << "\n";
                return;
            }
        }
        
        int low = 0, high = n, ans = high + 1;
        for (int i = 1; i <= m; ++i) {
            low = max(low, exam[i][0]);
        }
        while (low <= high) {
            int mid = (low + high) / 2;
            vector<int> time(n, 0);
            for (int i = 1; i <= m; ++i) {
                auto it = upper_bound(exam[i].begin(), exam[i].end(), mid);
                --it;
                time[*it] += a[i];
            }
            long long sum = 0;
            bool valid = true;
            for (int i = 0; valid && i < n; ++i) {
                if (time[i]) {
                    sum -= time[i];
                } else {
                    ++sum;
                }
                if (sum < 0) {
                    valid = false;
                }
            }
            if (valid) {
                high = mid - 1;
                ans = mid + 1;
            } else {
                low = mid + 1;
            }
        }
        out << (ans == n + 1 ? -1 : ans) << "\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    D732 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}