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

class C478 {
public:
    void solve(istream& in, ostream& out) {
        long long arr[3];
        in >> arr[0] >> arr[1] >> arr[2];
        sort(arr, arr+3);
        
        if (arr[2] > (arr[0] + arr[1]) * 2) {
            arr[2] = 2 * (arr[0] + arr[1]);
        }
        out << (arr[0] + arr[1] + arr[2]) / 3 << "\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false);

    C478 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}