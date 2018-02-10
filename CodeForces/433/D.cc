#include <bits/stdc++.h>

using namespace std;

class TaskD {
public:
    void solve(istream& in, ostream& out) {
        int n, m, k;
        in >> n >> m >> k;
        vector<tuple<int, int, int, int>> flight(m);
        for (int i = 0; i < m; ++i) {
            int d, f, t, c;
            in >> d >> f >> t >> c;
            flight[i] = {d, f, t, c};
        }
        sort(flight.begin(), flight.end());
        
        constexpr int MXV = 1'000'000;
        constexpr long long INF = 1'000'000'000'000'000'000LL;
        vector<long long> cost_back(MXV + 1, INF);
        vector<int> cost_jury(n + 1, 0);
        int poss_jury = 0;
        long long sum_jury = 0;
        for (int i = m - 1; i >= 0; --i) {
            auto [d, f, t, c] = flight[i];
            if (f != 0) { // no back flight
                continue;
            }
            assert(t > 0);
            if (!cost_jury[t]) {
                ++poss_jury;
                sum_jury += c;
                cost_jury[t] = c;
            } else {
                if (c < cost_jury[t]) {
                    sum_jury += c - cost_jury[t];
                    cost_jury[t] = c;
                }
            }
            if (poss_jury == n) {
                cost_back[d] = sum_jury;
                //cout << "go back " << d << " " << sum_jury << endl;
            }
        }
        for (int i = MXV - 1; i >= 0; --i) {
            cost_back[i] = min(cost_back[i], cost_back[i + 1]);
        }
        
        long long res = INF;
        poss_jury = sum_jury = 0;
        cost_jury.assign(n + 1, 0);
        for (int i = 0; i < m; ++i) {
            auto [d, f, t, c] = flight[i];
            if (t != 0) {
                continue;
            }
            assert(f > 0);
            if (!cost_jury[f]) {
                ++poss_jury;
                sum_jury += c;
                cost_jury[f] = c;
            } else {
                if (c < cost_jury[f]) {
                    sum_jury += c - cost_jury[f];
                    cost_jury[f] = c;
                }
            }
            if (poss_jury == n && d + k + 1 <= MXV) {
                //cout << "go " << d << " and back " << d + k + 1 << ": ";
                long long tmp = sum_jury + cost_back[d + k + 1];
                //cout << sum_jury << "+" << cost_back[d + k + 1] << endl;
                res = min(res, tmp);
            }
        }
        out << ((res < INF) ? res : -1) << "\n";
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
