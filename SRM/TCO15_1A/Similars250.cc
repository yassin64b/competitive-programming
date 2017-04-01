#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cmath>
#include <cstdlib>


using namespace std;

class Similars {
public:
    int maxsim(int, int);
};

int S(int x, int y) {
    int xc[10]{}, yc[10]{};
    while (x) {
        xc[x%10] = 1;
        x /= 10;
    }
    while (y) {
        yc[y%10] = 1;
        y /= 10;
    }
    int res = 0;
    for (int i = 0; i < 10; ++i) {
        res += xc[i] && yc[i];
    }
    return res;
}

int Similars::maxsim(int L, int R) {
    int res = 0;
    for (int a = L; a <= R; ++a) {
        for (int b = a+1; b <= min(a+100, R); ++b) {
            if (a != b) {
                res = max(res, S(a, b));
            }
        }
    }
    return res;
}