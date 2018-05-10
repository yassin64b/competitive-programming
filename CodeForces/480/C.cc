#include <bits/stdc++.h>

using namespace std;

class TaskC {
public:
    void solve(istream& in, ostream& out) {
        int n, k;
        in >> n >> k;
        vector<int> p(n);
        for (int i = 0; i < n; ++i) {
            in >> p[i];
        }
        vector<pair<int, int>> groups;
        for (int i = 0; i < n; ++i) {
            int m = groups.size();
            bool found = false;
            for (int j = 0; j < m; ++j) {
                int mn = groups[j].first, mx = groups[j].second;
                if (mn <= p[i] && mx >= p[i]) {
                    found = true;
                }
            }
            if (!found) {
                for (int j = 0; j < m; ++j) {
                    int mn = groups[j].first, mx = groups[j].second;
                    if (mx < p[i]) {
                        mx = p[i];
                        if (mx - mn + 1 <= k) {
                            found = true;
                            groups[j].second = p[i];
                        }
                    }
                }
            }
            if (!found) {
                int start = max(p[i] - k + 1, 0);
                for (int j = 0; j < m; ++j) {
                    if (groups[j].second < p[i]) {
                        start = max(start, groups[j].second + 1);
                    }
                }
                groups.emplace_back(start, p[i]);
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < (int)groups.size(); ++j) {
                int mn = groups[j].first, mx = groups[j].second;
                if (mn <= p[i] && mx >= p[i]) {
                    out << mn << " ";
                    break;
                }
            }
        }
        out << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskC solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
