/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author yassin
 */

#include <bits/stdc++.h>

using namespace std;

class TaskE {
public:
    void solve(istream &in, ostream &out) {
        int n;
        in >> n;
        vector<int> l(n), r(n);
        vector<int> nums;
        for (int i = 0; i < n; ++i) {
            in >> l[i] >> r[i];
            nums.push_back(l[i]);
            nums.push_back(r[i]);
            nums.push_back(r[i] + 1);
        }
        sort(nums.begin(), nums.end());
        map<int, int> m;
        int cur = 0;
        for (int x : nums) {
            if (m.count(x) == 0) {
                m[x] = ++cur;
            }
        }
        constexpr int MXV = 600'001;
        vector<int> tvset(MXV + 1, 0);
        for (int i = 0; i < n; ++i) {
            l[i] = m[l[i]];
            r[i] = m[r[i]];
            ++tvset[l[i]];
            --tvset[r[i] + 1];
        }
        for (int i = 1; i <= MXV; ++i) {
            tvset[i] += tvset[i - 1];
        }
        vector<int> pref_not_red(MXV + 1, 0);
        pref_not_red[0] = 1;
        for (int i = 1; i <= MXV; ++i) {
            pref_not_red[i] = pref_not_red[i - 1] + (tvset[i] < 2);
        }
        for (int i = 0; i < n; ++i) {
            if (pref_not_red[r[i]] - pref_not_red[l[i] - 1] == 0) {
                out << i + 1 << "\n";
                return;
            }
        }
        out << -1 << "\n";
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
