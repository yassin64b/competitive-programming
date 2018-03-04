#include <bits/stdc++.h>

using namespace std;

class TaskB {
public:
    void solve(istream& in, ostream& out) {
        string s;
        in >> s;
        int n = s.size();
        int cnt[26][5001][26]{};
        for (int i = 0; i < n; ++i) {
            for (int pos = i + 1; pos < i + n; ++pos) {
                int rpos = pos % n;
                ++cnt[s[i] - 'a'][pos - i][s[rpos] - 'a'];
            }
        }
        int num = 0;
        int m[26][5001]{};
        int mres[26]{};
        for (int i = 0; i < n; ++i) {
            for (int pos = i + 1; pos < i + n; ++pos) {
                int rpos = pos % n;
                if (cnt[s[i] - 'a'][pos - i][s[rpos] - 'a'] == 1) {
                    ++m[s[i] - 'a'][pos - i];
                    mres[s[i] - 'a'] = max(mres[s[i] - 'a'], m[s[i] - 'a'][pos - i]);
                }
            }
        }
        for (int x : mres) {
            num += x;
        }
        out.precision(17);
        out << fixed << (double)num / n << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskB solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
