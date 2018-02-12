#include <bits/stdc++.h>

using namespace std;

class ccc01s5 {
    bool brute(string &s1, string &s2, int k, const int m, const int n,
            const vector<string> &a, const vector<string> &b, vector<int> &res)
    {
        if (k > m) {
            return false;
        } else if (k > 0 && s1 == s2) {
            return true;
        }
        int l1 = s1.size(), l2 = s2.size();
        for (int i = 0; i < n; ++i) {
            s1 += a[i];
            s2 += b[i];
            int nl1 = s1.size(), nl2 = s2.size();
            int x = min(l1, l2), y = min(nl1, nl2);
            bool ok = true;
            for (int j = x; j < y; ++j) {
                if (s1[j] != s2[j]) {
                    ok = false;
                }
            }
            if (ok) {
                if (brute(s1, s2, k + 1, m, n, a, b, res)) {
                    res.push_back(i + 1);
                    return true;
                }
            }
            s1.erase(l1);
            s2.erase(l2);
        }
        return false;
    }
public:
    void solve(istream& in, ostream& out) {
        int m, n;
        in >> m >> n;
        vector<string> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            in >> b[i];
        }
        vector<int> res;
        string s1, s2;
        bool found = brute(s1, s2, 0, m, n, a, b, res);
        if (!found) {
            out << "No solution.\n";
        } else {
            reverse(res.begin(), res.end());
            out << res.size() << "\n";
            for (int i : res) {
                out << i << "\n";
            }
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    ccc01s5 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
