#include <bits/stdc++.h>

using namespace std;

class TaskC {
public:
    void solve(istream& in, ostream& out) {
        int n, k;
        string s;
        in >> n >> k >> s;
        int cnt[26]{};
        for (char c : s) {
            ++cnt[c - 'a'];
        }
        int sum = 0;
        for (int i = 0; i < 26; ++i) {
            if (sum >= k) {
                cnt[i] = 0;
            } else if (sum + cnt[i] <= k) {
                cnt[i] = cnt[i];
            } else {
                cnt[i] = k - sum;
            }
            sum += cnt[i];
        }
        string t;
        for (char c : s) {
            if (cnt[c - 'a']) {
                --cnt[c - 'a'];
            } else {
                t += c;
            }
        }
        out << t << "\n";
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
