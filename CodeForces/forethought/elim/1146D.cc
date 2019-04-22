#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

void dfs(int cur, int upto, int &cnt, vector<int> &vis, int a, int b) {
    if (cur - b >= 0 && !vis[cur - b]) {
        vis[cur - b] = 1;
        ++cnt;
        dfs(cur - b, upto, cnt, vis, a, b);
    }
    if (cur + a <= upto && !vis[cur + a]) {
        vis[cur + a] = 1;
        ++cnt;
        dfs(cur + a, upto, cnt, vis, a, b);
    }
}

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int m, a, b;
    cin >> m >> a >> b;
    int g = gcd(a, b);
    vector<int> vis(10'000'000, 0);
    vis[0] = 1;
    int cnt = 1;
    long long res = 1;
    for (int x = 1; x <= m; ++x) {
        if (x - a >= 0 && vis[x - a]) {
            vis[x] = 1;
            ++cnt;
            dfs(x, x, cnt, vis, a, b);
        }
        if (cnt >= x / g + 1 && x % g == 0) {
            /*for (int y = x; y <= m; ++y) { // too slow --> closed form
                res += y / g + 1;
            }*/
            int tmp = (m - x) / g;
            long long first = x + g, last = x + tmp * g;
            res += tmp * (first + last) / 2; // arith. progression
            res += (last / g + 1LL) * (m - last + 1); // last part
            break;
        }
        res += cnt;
    }
    cout << res << "\n";

    return 0;
}