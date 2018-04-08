#include <bits/stdc++.h>

using namespace std;

class TaskB {
public:
    void solve(istream& in, ostream& out) {
        int n, k, m;
        in >> n >> k >> m;
        vector<string> words(n);
        unordered_map<string, int> word_id;
        for (int i = 0; i < n; ++i) {
            in >> words[i];
            word_id[words[i]] = i;
        }
        vector<int> a(n), cost(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        for (int i = 0; i < k; ++i) {
            int x;
            in >> x;
            vector<int> cur(x);
            for (int j = 0; j < x; ++j) {
                in >> cur[j];
                --cur[j];
            }
            int mn_cost = a[word_id[words[cur[0]]]];
            for (int j = 1; j < x; ++j) {
                mn_cost = min(mn_cost, a[word_id[words[cur[j]]]]);
            }
            for (int j = 0; j < x; ++j) {
                cost[cur[j]] = mn_cost;
            }
        }
        long long ans = 0;
        for (int i = 0; i < m; ++i) {
            string s;
            in >> s;
            ans += cost[word_id[s]];
        }
        out << ans << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskB solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
