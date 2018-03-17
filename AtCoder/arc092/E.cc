#include <bits/stdc++.h>

using namespace std;

constexpr int INF = 1'000'000'001;

class arc092_e {
private:
    vector<int> solve(set<int> &take, vector<int> &a) {
        vector<int> res;
        int n = a.size();
        vector<int> keep(n, 0);
        for (int i = 0; i < n; ++i) {
            keep[i] = take.count(i);
        }
        while (keep.size() > 1U) {
            int m = keep.size();
            if (!keep[m - 1]) {
                res.push_back(m);
                keep.pop_back();
            } else if (!keep[0]) {
                res.push_back(1);
                keep.erase(begin(keep));
            } else {
                for (int i = 1; i + 1 < m; ++i) {
                    if (keep[i - 1] && keep[i + 1]) {
                        keep[i - 1] = 1;
                        res.push_back(i + 1);
                        keep.erase(begin(keep) + i, begin(keep) + i + 2);
                        break;
                    } else if (!keep[i - 1] && !keep[i] && !keep[i + 1]) {
                        keep[i - 1] = 0;
                        res.push_back(i + 1);
                        keep.erase(begin(keep) + i, begin(keep) + i + 2);
                        break;
                    }
                }
            }
        }
        return res;
    }
public:
    void solve(istream& in, ostream& out) {
        int N;
        in >> N;
        vector<int> a(N);
        for (int i = 0; i < N; ++i) {
            in >> a[i];
        }
        set<int> take0, take1;
        for (int i = 0; i < N; ++i) {
            if (a[i] >= 0) {
                if (i % 2) take1.insert(i);
                else take0.insert(i);
            }
        }
        if (take0.empty()) {
            int mx = -INF, ind = -1;
            for (int i = 0; i < N; i += 2) {
                if (a[i] > mx) {
                    mx = a[i];
                    ind = i;
                }
            }
            take0.insert(ind);
        }
        if (take1.empty()) {
            int mx = -INF, ind = -1;
            for (int i = 1; i < N; i += 2) {
                if (a[i] > mx) {
                    mx = a[i];
                    ind = i;
                }
            }
            take1.insert(ind);
        }
        long long sum0 = 0, sum1 = 0;
        for (int i : take0) sum0 += a[i];
        for (int i : take1) sum1 += a[i];
        vector<int> res;
        if (sum0 >= sum1) {
            res = solve(take0, a);
        } else {
            res = solve(take1, a);
        }
        out << max(sum0, sum1) << "\n" << res.size() << "\n";
        for (int x : res) {
            out << x << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    arc092_e solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
