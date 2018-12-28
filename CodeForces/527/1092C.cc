#include <bits/stdc++.h>

using namespace std;

class TaskC {
private:
    bool ok(string s, const vector<string> &v, string &res) {
        int n = s.size(), m = v.size();
        vector<int> pre_done(n, 0), suf_done(n, 0);
        for (int i = 0; i < m; ++i) {
            int l = v[i].size();
            if (!pre_done[l] && s.substr(0, l) == v[i]) {
                pre_done[l] = 1;
                res[i] = 'P';
            } else if (!suf_done[l] && s.substr(n - l) == v[i]) {
                suf_done[l] = 1;
                res[i] = 'S';
            } else {
                return false;
            }
        }
        return true;
    }
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<string> v(2 * n - 2);
        int i1 = -1, i2 = -1;
        for (int i = 0; i < 2 * n - 2; ++i) {
            in >> v[i];
            if ((int)v[i].size() == n - 1) {
                if (i1 == -1) {
                    i1 = i;
                } else {
                    i2 = i;
                }
            }
        }
        string res(2 * n - 2, 'P');
        // fix i1 as prefix, i2 as suffix
        string s = v[i1] + v[i2].back();
        if (ok(s, v, res)) {
            out << res << "\n";
        } else {
            // fix i1 as suffix, i2 as prefix
            s = v[i2] + v[i1].back();
            if (ok(s, v, res)) {
                out << res << "\n";
            } else {
                assert(false);
            }
        }
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
