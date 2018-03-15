#include <bits/stdc++.h>

using namespace std;

class kickstart_c {
private:
    // dfs: iterative
    void dfs(int u, const vector<vector<int>> &g, vector<int> &path) {
        while (!g[u].empty()) {
            assert(g[u].size() == 1U);
            path.push_back(u);
            path.push_back(g[u][0]);
            u = g[u][0];
        }
    }
    // dfs2: more memory
    void dfs2(int u, const vector<vector<int>> &g, vector<int> &path) {
        if (!g[u].empty()) {
            path.push_back(u);
            for (int v : g[u]) {
                path.push_back(v);
                dfs(v, g, path);
            }
        }
    }
public:
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        for (int t = 1; t <= T; ++t) {
            int n;
            in >> n;
            map<string, int> flight_to_id;
            vector<string> id_to_flight;
            vector<vector<int>> g(10001);
            for (int i = 0; i < n; ++i) {
                string a, b;
                in >> a >> b;
                if (flight_to_id.count(a) == 0) {
                    id_to_flight.push_back(a);
                    flight_to_id[a] = (int)id_to_flight.size() - 1;
                }
                if (flight_to_id.count(b) == 0) {
                    id_to_flight.push_back(b);
                    flight_to_id[b] = (int)id_to_flight.size() - 1;
                }
                g[flight_to_id[a]].push_back(flight_to_id[b]);
            }
            int m = id_to_flight.size();
            vector<bool> is_start(m, true);
            for (int i = 0; i < m; ++i) {
                for (int v : g[i]) {
                    is_start[v] = false;
                }
            }
            int start = -1;
            for (int i = 0; i < m; ++i) {
                if (is_start[i]) {
                    assert(start == -1);
                    start = i;
                }
            }
            assert(start != -1);
            vector<int> path;
            dfs(start, g, path);
            assert(path.size() % 2 == 0U);
            out << "Case #" << t << ":";
            for (int i = 0; i < (int)path.size(); i += 2) {
                out << " " << id_to_flight[path[i]] << "-" << id_to_flight[path[i + 1]];
            }
            out << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    kickstart_c solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
