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

class A372 {
public:
    void solve(istream &in, ostream &out) {
        int n;
        in >> n;
        vector<int> s(n);
        for (int i = 0; i < n; ++i) {
            in >> s[i];
        }
        sort(s.begin(), s.end());
        
        //binary search
        /*int low = 0, high = n / 2, ans = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            bool fits = true;
            //cout << mid << endl;
            for (int i = 0; fits && i < mid; ++i) {
                //cout << i << " " << n-mid+i << endl;
                if (2 * s[i] > s[n - mid + i]) {
                    fits = false;
                }
            }
            if (fits) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }*/
        
        //greedy, sorting is dominant so O(n*logn) too
        int ans = 0;
        for (int i = 0, j = n/2; i < n/2; ++i) {
            while (j < n && 2*s[i] > s[j]) {
                ++j;
            }
            if (j < n) {
                ++ans;
                ++j;
            }
        }
        out << n-ans << "\n";
        
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    A372 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
