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

class CoinConstruction {
public:
    vector <int> construct(int);
};

vector <int> CoinConstruction::construct(int k) {
    int sum = 1;
    vector<int> res{1};
    int i;
    for (i = (1 << 20); ; i >>= 1) {
        if (k & i) {
            break;
        }
    }
    i >>= 1;
    for ( ; i; i >>= 1) {
        if (k & i) {
            res.push_back(sum + 1);
            sum += sum + 1;
        } else {
            res.push_back(sum);
            sum += sum;
        }
    }
    return res;
}