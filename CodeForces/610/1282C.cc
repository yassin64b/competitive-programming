#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int M;
    cin >> M;
    for (int m = 0; m < M; ++m) {
        long long n, T, a, b;
        cin >> n >> T >> a >> b;
        vector<long long> hard(n);
        long long num_hard = 0;
        for (int i = 0; i < n; ++i) {
            cin >> hard[i];
            num_hard += hard[i];
        }
        long long num_easy = n - num_hard;
        vector<pair<long long, long long>> p(n);
        vector<long long> t(n);
        for (int i = 0; i < n; ++i) {
            cin >> t[i];
            p[i] = {t[i], hard[i]};
        }
        p.push_back({T + 1, -1});
        sort(begin(p), end(p));
        long long t_needed = 0;
        long long mx_pts = 0;
        for (int i = 0, j = 0; i <= n; ++i) {
            // leave at time p[i].first - 1
            const long long t_leave = p[i].first - 1;
            while (j < n && p[j].first <= t_leave) {
                int is_hard = p[j].second;
                t_needed += (is_hard ? b : a);
                num_hard -= is_hard;
                num_easy -= !is_hard;
                ++j;
            }
            if (t_needed > t_leave) {
                continue;
            }
            long long cur_pts = j;
            long long t_left = t_leave - t_needed;
            long long solve_easy = min(num_easy, t_left / a);
            t_left -= solve_easy * a;
            cur_pts += solve_easy;
            long long solve_hard = min(num_hard, t_left / b);
            cur_pts += solve_hard;
            mx_pts = max(mx_pts, cur_pts);
        }
        cout << mx_pts << "\n";
    }
    return 0;
}