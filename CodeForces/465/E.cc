#include <bits/stdc++.h>

using namespace std;

struct mm {
    int mx, mn;
};
class TaskE {
private:
    void dfs(int u, const vector<vector<int>> &g, const vector<int> &val,
             vector<vector<mm>> &dp, const int n, const bool flag)
    {
        if (val[u] != -1) {
            assert(g[u].size() == 0U);
            dp[u][0] = {val[u], val[u]};
            return;
        } else {
            assert(val[u] == -1);
            assert(g[u].size() == 2U);
        }
        int x = g[u][0], y = g[u][1];
        dfs(x, g, val, dp, n, flag);
        dfs(y, g, val, dp, n, flag);
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; i + j <= n; ++j) {
                if (flag) {
                    dp[u][i+j].mx = max(dp[u][i+j].mx, dp[x][i].mx - dp[y][j].mn);
                    if (i + j + 1 <= n)
                        dp[u][i+j+1].mx = max(dp[u][i+j+1].mx, dp[x][i].mx + dp[y][j].mx);
                    dp[u][i+j].mn = min(dp[u][i+j].mn, dp[x][i].mn - dp[y][j].mx);
                    if (i + j + 1 <= n)
                        dp[u][i+j+1].mn = min(dp[u][i+j+1].mn, dp[x][i].mn + dp[y][j].mn);
                } else {
                    if (i + j + 1 <= n)
                        dp[u][i+j+1].mx = max(dp[u][i+j+1].mx, dp[x][i].mx - dp[y][j].mn);
                    dp[u][i+j].mx = max(dp[u][i+j].mx, dp[x][i].mx + dp[y][j].mx);
                    if (i + j + 1 <= n)
                        dp[u][i+j+1].mn = min(dp[u][i+j+1].mn, dp[x][i].mn - dp[y][j].mx);
                    dp[u][i+j].mn = min(dp[u][i+j].mn, dp[x][i].mn + dp[y][j].mn);
                }
            }
        }
    }
public:
    void solve(istream& in, ostream& out) {
        string expr;
        in >> expr;
        int P, M;
        in >> P >> M;
        
        stringstream ss(expr);
        char c;
        queue<char> output;
        stack<char> ops;
        while (ss >> c) {
            if (isdigit(c)) {
                output.push(c);
            } else if (c == '(') {
                ops.push(c);
            } else if (c == ')') {
                while (ops.top() != '(') {
                    output.push(ops.top());
                    ops.pop();
                }
                ops.pop();
            } else {
                while (!ops.empty() && ops.top() != '(') {
                    output.push(ops.top());
                    ops.pop();
                }
                ops.push(c);
            }
        }
        while (!ops.empty()) {
            output.push(ops.top());
            ops.pop();
        }
        
        constexpr int MXN = 50'000;
        vector<vector<int>> g(MXN);
        vector<int> val(MXN, -1);
        int id = 0;
        stack<int> st;
        while (!output.empty()) {
            c = output.front();
            output.pop();
            if (isdigit(c)) {
                val[id] = c - '0';
                st.push(id);
                ++id;
            } else {
                assert(c == '?');
                int x, y;
                y = st.top(); st.pop();
                x = st.top(); st.pop();
                st.push(id);
                g[id].push_back(x);
                g[id].push_back(y);
                ++id;
            }
        }
        int root = st.top();
        constexpr int INF = 1'000'000'000;
        vector<vector<mm>> dp(id + 1, vector<mm>(min(P, M) + 1, {-INF, INF}));
        dfs(root, g, val, dp, min(P, M), (min(P, M) == P ? 1 : 0));
        out << dp[root][min(P, M)].mx << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskE solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
