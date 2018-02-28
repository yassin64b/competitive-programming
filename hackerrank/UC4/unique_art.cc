#include <cmath>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Query {
    int L, R, i;
};
constexpr int MAX = 1'000'000;
int ans = 0;
int cnt[MAX + 1], t[MAX + 1], res[MAX + 1];
Query q[MAX + 1];

void add(int i) {
    ++cnt[t[i]];
    ans += cnt[t[i]] == 1;
    ans -= cnt[t[i]] == 2;
}

void remove(int i) {
    --cnt[t[i]];
    ans += cnt[t[i]] == 1;
    ans -= cnt[t[i]] == 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }
    int id = -1;
    unordered_map<int, int> m;
    for (int i = 0; i < n; ++i) {
        if (m.count(t[i]) == 0) {
            m[t[i]] = ++id;
        }
        t[i] = m[t[i]];
    }
    
    int sqrt_n = sqrt(n);
    
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        cin >> q[i].L >> q[i].R;
        --q[i].L;
        --q[i].R;
        q[i].i = i;
    }

    sort(q, q + Q, [sqrt_n](const Query &lhs, const Query &rhs) {
        if (lhs.L / sqrt_n == rhs.L / sqrt_n) { //same block
            return lhs.R < rhs.R;
        }
        return lhs.L / sqrt_n < rhs.L / sqrt_n; //sort by block
    });

    int curL = 0, curR = 0;
    for (int i = 0; i < Q; ++i) {
        int L = q[i].L, R = q[i].R;
        while (curL < L) {
            remove(curL);
            ++curL;
        }
        while (curL > L) {
            add(curL - 1);
            --curL;
        }
        while (curR <= R) {
            add(curR);
            ++curR;
        }
        while (curR > R + 1) {
            remove(curR - 1);
            --curR;
        }
        res[q[i].i] = ans;
    }

    for (int i = 0; i < Q; ++i) {
        cout << res[i] << "\n";
    }
    return 0;
}