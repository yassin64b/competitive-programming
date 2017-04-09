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

class WaterAndOxygen {
public:
    double maxDays(int, int, int, int);
};

double WaterAndOxygen::maxDays(int remainH20, int remainO2, int costH2O, int costO2) {
    double low = 0, high = remainH20 / (double)costH2O;
    for (int i = 0; i < 1000; ++i) {
        double mid = (low + high) / 2;
        double water = remainH20 - (costH2O * mid);
        double oxy = remainO2 + water / 2 - (costO2 * mid);
        if (water < 0 || oxy < 0) {
            high = mid;
        } else {
            low = mid;
        }
    }
    return (low + high) / 2;
}
