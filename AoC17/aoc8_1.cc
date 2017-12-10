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

class aoc8_1 {
public:
    void solve(istream& in, ostream& out) {
        map<string, int> val;
        while (in) {
            string reg1, op1, s_if, reg2, op2;
            int num1, num2;
            in >> reg1 >> op1 >> num1 >> s_if >> reg2 >> op2 >> num2;
            if (op1 == "dec")
                num1 *= -1;
            bool res = false, invert = false;
            if (op2 == ">" || op2 == "<=") {
                invert = op2 == "<=";
                res = val[reg2] > num2;
            } else if (op2 == "<" || op2 == ">=") {
                invert = op2 == ">=";
                res = val[reg2] < num2;
            } else if (op2 == "==" || op2 == "!=") {
                invert = op2 == "!=";
                res = val[reg2] == num2;
            }
            if (res != invert)
                val[reg1] += num1;
        }
        int res = -1000 * 1000 * 1000;
        for (const auto& p : val)
            res = max(res, p.second);
        out << res << "\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    aoc8_1 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
