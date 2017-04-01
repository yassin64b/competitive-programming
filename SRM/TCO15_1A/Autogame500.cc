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

class Autogame {
public:
    int wayscnt(vector <int>, int);
};
constexpr int MOD = 1000*1000*1000+7;
int Autogame::wayscnt(vector <int> a, int K) {
    int N = a.size();
    vector<int> cur(N, 1);
    set<vector<int>> seen;
    seen.insert(cur);
    for (int i = 0; i < K; ++i) {
        vector<int> nxt(N, 0);
        for (int j = 0; j < N; ++j) {
            nxt[a[j]-1] += cur[j];
        }
        cur = nxt;
        if (seen.find(cur) != seen.end()) {
            break;
        }
        seen.insert(cur);
    }
    long long res = 1;
    for (int i = 0; i < N; ++i) {
        res *= cur[i]+1;
        res %= MOD;
    }
    return res;
}