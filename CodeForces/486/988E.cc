#include <bits/stdc++.h>

using namespace std;

class TaskE {
private:
    int make(string &s, char a, int pos) {
        int m = s.size();
        for (int j = m + pos; j >= 0; --j) {
            if (s[j] == a) {
                for (int k = j + 1; k <= m + pos; ++k) {
                    swap(s[k], s[k - 1]);
                }
                return m + pos - j;
            }
        }
        return -1'000;
    }
    int fix(string &s) {
        int m = s.size();
        int first_non_zero = 0;
        while (s[first_non_zero] == '0') {
            ++first_non_zero;
        }
        if (first_non_zero >= m - 2 && m > 2) {
            return 1'000;
        }
        return first_non_zero;
    }
public:
    void solve(istream& in, ostream& out) {
        string n;
        in >> n;
        int res = 1'000;
        if (count(begin(n), end(n), '0') >= 2) {
            string s(n);
            res = min(res, make(s, '0', -1) + make(s, '0', -2) + fix(s));
        }
        if (count(begin(n), end(n), '2') >= 1 && count(begin(n), end(n), '5') >= 1) {
            string s(n);
            res = min(res, make(s, '5', -1) + make(s, '2', -2) + fix(s));
        }
        if (count(begin(n), end(n), '5') >= 1 && count(begin(n), end(n), '0') >= 1) {
            string s(n);
            res = min(res, make(s, '0', -1) + make(s, '5', -2) + fix(s));
        }
        if (count(begin(n), end(n), '7') >= 1 && count(begin(n), end(n), '5') >= 1) {
            string s(n);
            res = min(res, make(s, '5', -1) + make(s, '7', -2) + fix(s));
        }
        out << (res == 1'000 ? -1 : res) << "\n";
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
