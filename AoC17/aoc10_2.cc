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

class aoc10_2 {
public:
    void solve(istream &in, ostream &out) {
        constexpr int n = 256;
        vector<int> lst(n);
        for (int i = 0; i < n; ++i)
            lst[i] = i;
        string input;
        getline(in, input);
        vector<int> lens;
        for (char c : input)
            lens.push_back(c);
        for (int x : {17, 31, 73, 47, 23})
            lens.push_back(x);
        int m = lens.size();
        int cur = 0, skip = 0;
        for (int round = 0; round < 64; ++round) {
            for (int j = 0; j < m; ++j) {
                int len = lens[j];
                for (int i = 0; i < len / 2; ++i) {
                    int a = (cur + i) % n;
                    int b = (cur + len - 1 - i) % n;
                    swap(lst[a], lst[b]);
                }
                cur += len + skip;
                cur %= n;
                ++skip;
            }
        }
        vector<int> dense(16);
        for (int i = 0; i < 16; ++i) {
            for (int j = i * 16; j < (i + 1) * 16; ++j) {
                dense[i] ^= lst[j];
            }
        }
        string hexadec;
        for (int i = 0; i < 16; ++i) {
            int tmp = dense[i] / 16;
            hexadec += (tmp < 10 ? tmp + '0' : tmp - 10 + 'a');
            tmp = dense[i] % 16;
            hexadec += (tmp < 10 ? tmp + '0' : tmp - 10 + 'a');
        }
        
        out << hexadec << "\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    aoc10_2 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
