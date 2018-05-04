#include <bits/stdc++.h>

using namespace std;

class StablePairsDiv1 {
public:
    vector <int> findMaxStablePairs(int, int, int);
};

vector <int> StablePairsDiv1::findMaxStablePairs(int n, int c, int k) {
    vector<int> res{n, n - 1};
    int last = n + n - 1;
    for (int i = 1; i < k; ++i) {
        // last - cur != c
        int tmp = last - c;
        if (tmp % 2 == 1) {
            res.push_back(tmp / 2 + 1);
            res.push_back(tmp / 2);
        } else {
            res.push_back(tmp / 2 + 1);
            res.push_back(tmp / 2 - 1);
        }
        last = res[2 * i] + res[2 * i + 1];
    }
    reverse(begin(res), end(res));
    for (int i = 0; i + 1 < 2 * k; ++i) {
        if (res[i] >= res[i + 1] || res[i] < 1) {
            return {};
        }
    }
    return res;
}