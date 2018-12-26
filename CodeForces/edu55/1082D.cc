#include <bits/stdc++.h>

using namespace std;

class TaskD {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<pair<int, int>> a(n);
        vector<int> la(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i].first;
            a[i].second = i;
            la[i] = a[i].first;
        }
        sort(begin(a), end(a));
        int v1 = a[0].second, v2 = a[1].second;
        vector<int> path{v1}, deg(n, 0);
        vector<pair<int, int>> e;
        int j;
        for (j = n - 1; j > 1 && a[j].first >= 2; --j) { // build path
            e.emplace_back(path.back(), a[j].second);
            ++deg[path.back()];
            ++deg[a[j].second];
            path.push_back(a[j].second);
        }
        e.emplace_back(path.back(), v2);
        ++deg[path.back()];
        ++deg[v2];
        path.push_back(v2);
        for (int k = 1; j > 1; --j) { // append in middle of path
            while (k < (int)path.size() && la[path[k]] == deg[path[k]]) {
                ++k;
            }
            if (k < (int)path.size()) {
                e.emplace_back(path[k], a[j].second);
                ++deg[path[k]];
            } else {
                out << "NO\n";
                return;
            }
        }
        
        out << "YES " << (int)path.size() - 1 << "\n";
        out << e.size() << "\n";
        for (auto [u, v] : e) {
            out << u + 1 << " " << v + 1 << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskD solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
