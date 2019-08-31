#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        i64 n, m;
        cin >> n >> m;
        vector<int> vis(10, 0);
        i64 cur = m, sum = 0;
        int cnt_done = 0;
        while (n >= cur && !vis[cur % 10]) {
            vis[cur % 10] = 1;
            sum += cur % 10;
            ++cnt_done;
            cur += m;
        }
        i64 sum_cycle = 0;
        int len_cycle = 0;
        vis.assign(10, 0);
        while (!vis[cur % 10]) {
            vis[cur % 10] = 1;
            sum_cycle += cur % 10;
            ++len_cycle;
            cur += m;
        }
        n -= m * cnt_done;
        i64 cnt_cycle = n / (len_cycle * m);
        sum += cnt_cycle * sum_cycle;
        n -= cnt_cycle * len_cycle * m;
        cur = m;
        while (n >= cur) {
            sum += cur % 10;
            cur += m;
        }
        cout << sum << "\n";
    }
    return 0;
}