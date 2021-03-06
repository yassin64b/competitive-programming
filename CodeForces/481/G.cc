#include <bits/stdc++.h>

using namespace std;

class TaskG {
public:
    void solve(istream& in, ostream& out) {
        int n, m;
        in >> n >> m;
        vector<int> s_(m), d_(m), c_(m);
        vector<tuple<int, int, int, int>> sdc(m);
        for (int i = 0; i < m; ++i) {
            in >> s_[i] >> d_[i] >> c_[i];
            --s_[i];
            --d_[i];
            sdc[i] = {s_[i], d_[i], c_[i], i};
        }
        sort(begin(sdc), end(sdc));
        
        priority_queue<pair<int, int>> pq;
        vector<int> res(n, 0);
        for (int i = 0; i < m; ++i) {
            res[d_[i]] = m + 1;
        }
        for (int i = 0, j = 0; i < n; ++i) {
            while (j < m && get<0>(sdc[j]) == i) {
                int s, d, c, k;
                tie(s, d, c, k) = sdc[j];
                pq.emplace(-d, k);
                ++j;
            }
            if (pq.empty() || res[i]) {
                continue;
            }
            int d = -pq.top().first, k = pq.top().second;
            res[i] = k + 1;
            if (--c_[k] == 0) {
                pq.pop();
                if (i >= d_[k]) {
                    out << -1 << "\n";
                    return;
                }
            }
        }
        if (!pq.empty()) {
            out << -1 << "\n";
            return;
        }
        for (int x : res) {
            out << x << " ";
        }
        out << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskG solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
