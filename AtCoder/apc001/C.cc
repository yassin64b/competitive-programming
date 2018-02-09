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
#include <sstream>

using namespace std;

class apc001_c {
public:
    void solve(istream& in, ostream& out) {
        int N;
        cin >> N;
        string s;
        cout << 0 << endl;
        cin >> s;
        if (s == "Vacant") {
            return;
        }
        int male = (s == "Female");
        int low = 1, high = N - 1, ans = low;
        while (low <= high) {
            int mid = (low + high) / 2;
            cout << mid << endl;
            cin >> s;
            if (s == "Vacant") {
                return;
            } else if (s == "Female") {
                if (mid % 2 == male) {
                    high = mid - 1;
                } else {
                    ans = mid;
                    low = mid + 1;
                }
            } else {
                if (mid % 2 == male) {
                    ans = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        cout << ans << endl;
        cin >> s;
        assert(s == "Vacant");
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    apc001_c solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}

