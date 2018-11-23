#include <bits/stdc++.h>

using namespace std;

class C439 {
public:
    void solve(istream& in, ostream& out) {
        int n, k, p;
        in >> n >> k >> p;
        vector<int> a(n);
        int cnt_even = 0;
        for (int i = 0; i < n; ++i) {
            in >> a[i];
            cnt_even += (a[i] % 2 == 0);
        }
        long long sum = accumulate(begin(a), end(a), 0LL);
        if (sum % 2 != (k - p) % 2) {
            out << "NO\n";
            return;
        }
        int cnt_odd = n - cnt_even;
        int num_double_odd = max(0, p - cnt_even);
        if (cnt_even + cnt_odd / 2 >= p && cnt_odd - 2 * num_double_odd >= k - p) {
            out << "YES\n";
            vector<vector<int>> even, odd;
            for (int i = 0; i < n; ++i) {
                if (a[i] % 2 == 0) {
                    if ((int)even.size() <= p) {
                        even.push_back({a[i]});
                    } else {
                        even.back().push_back(a[i]);
                    }
                } else {
                    if ((int)odd.size() <= k - p) {
                        odd.push_back({a[i]});
                    } else {
                        odd.back().push_back(a[i]);
                    }
                }
            }
            while ((int)even.size() < p) {
                even.emplace_back();
                even.back().push_back(odd.back().back());
                odd.back().pop_back();
                even.back().push_back(odd.back().back());
                odd.back().pop_back();
            }
            while ((int)odd.size() > k - p) {
                while (!odd.back().empty()) {
                    if (p > 0) {
                        even[0].push_back(odd.back().back());
                        odd.back().pop_back();
                        even[0].push_back(odd.back().back());
                        odd.back().pop_back();
                    } else {
                        odd[0].push_back(odd.back().back());
                        odd.back().pop_back();
                        odd[0].push_back(odd.back().back());
                        odd.back().pop_back();
                    }
                }
                odd.pop_back();
            }
            while ((int)even.size() > p) {
                while (!even.back().empty()) {
                    if (p > 0) {
                        even[0].push_back(even.back().back());
                        even.back().pop_back();
                    } else {
                        odd[0].push_back(even.back().back());
                        even.back().pop_back();
                    }
                }
                even.pop_back();
            }
            for (const auto &v : even) {
                out << v.size();
                for (int x : v) {
                    out << " " << x;
                }
                out << "\n";
            }
            for (const auto &v : odd) {
                out << v.size();
                for (int x : v) {
                    out << " " << x;
                }
                out << "\n";
            }
        } else {
            out << "NO\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    C439 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
