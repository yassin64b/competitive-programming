#include <bits/stdc++.h>

using namespace std;

constexpr int INF = 1'000;
int brute(vector<string> &s, int len,
          const vector<vector<pair<int, int>>> &diag) {
    const int N = s.size();
    if (len == 0) {
        for (auto &v : s) {
            for (char c : v) {
                if (c == 0) {
                    return INF;
                } else {
                    assert(c == 1);
                }
            }
        }
        return 0;
    }
    vector<vector<int>> inds(N, vector<int>(N, 0));
    map<int, int> id, rid;
    int cnt = 0;
    for (int i = 0; i < (int)diag.size(); ++i) {
        if ((int)diag[i].size() == len) {
            id[i] = cnt;
            rid[cnt] = i;
            ++cnt;
        }
        if ((int)diag[i].size() < len) {
            for (const auto &p : diag[i]) {
                ++inds[p.first][p.second];
            }
        }
    }
    int res = INF;
    for (int mask = 0; mask < (1 << cnt); ++mask) {
        int cost = 0;
        for (int j = 0; j < cnt; ++j) {
            if (!(mask & (1 << j))) continue;
            ++cost;
            int i = rid[j];
            for (const auto &p : diag[i]) {
                s[p.first][p.second] = 1 - s[p.first][p.second];
            }
        }
        bool ok = true;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (inds[i][j] == 0 && s[i][j] == 0) {
                    ok = false;
                }
            }
        }
        if (ok) {
            res = min(res, cost + brute(s, len - 1, diag));
        }
        for (int j = 0; j < cnt; ++j) {
            if (!(mask & (1 << j))) continue;
            int i = rid[j];
            for (const auto &p : diag[i]) {
                s[p.first][p.second] = 1 - s[p.first][p.second];
            }
        }
    }
    return res;
}

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int N;
        cin >> N;
        vector<string> s(N);
        for (int i = 0; i < N; ++i) {
            cin >> s[i];
            for (int j = 0; j < N; ++j) {
                s[i][j] = (s[i][j] == '#');
            }
        }
        vector<vector<pair<int, int>>> diags;
        for (int a = 0; a < N; ++a) {
            vector<pair<int, int>> cur;
            for (int i = a, j = 0; i >= 0 && j < N; --i, ++j)
                cur.emplace_back(i, j);
            diags.push_back(cur);
            cur.clear();
            for (int i = a, j = 0; i < N && j < N; ++i, ++j)
                cur.emplace_back(i, j);
            diags.push_back(cur);
        }
        for (int a = 1; a < N; ++a) {
            vector<pair<int, int>> cur;
            for (int i = N - 1, j = a; i >= 0 && j < N; --i, ++j)
                cur.emplace_back(i, j);
            diags.push_back(cur);
            cur.clear();
            for (int i = 0, j = a; i < N && j < N; ++i, ++j) 
                cur.emplace_back(i, j);
            diags.push_back(cur);
        }
        int ans = brute(s, N, diags);
        cout << "Case #" << t << ": " << ans << "\n";
    }


    return 0;
}