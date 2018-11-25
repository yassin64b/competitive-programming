#include <bits/stdc++.h>

using namespace std;

constexpr int B = 33, MOD = 1'000'000'009;

class TaskE {
private:
    int val(int i, int len, const vector<int> &F, const vector<int> &powb) {
        ++i;
        int j = i + len - 1;
        int res = (F[j] - 1LL * F[i - 1] * powb[j - i + 1]) % MOD;
        if (res < 0) res += MOD;
        return res;
    }
public:
    void solve(istream& in, ostream& out) {
        string s, t;
        in >> s >> t;
        int n = s.size(), m = t.size();
        if (s[0] == '1') {
            for (char &c : s) {
                if (c == '1') c = '0';
                else c = '1';
            }
        }
        vector<int> powb(m + 1, 1);
        for (int j = 1; j <= m; ++j) {
            powb[j] = (1LL * B * powb[j - 1]) % MOD;
        }
        int ind1 = -1;
        for (ind1 = 0; ind1 < n; ++ind1) {
            if (s[ind1] == '1') {
                break;
            }
        }
        vector<int> F(m + 1, 1);
        for (int j = 0; j < m; ++j) {
            int v = t[j] - 'a';
            F[j + 1] = (1LL * B * F[j] + v) % MOD;
        }
        int cnt0 = count(begin(s), end(s), '0'), cnt1 = n - cnt0;
        vector<int> cnt(26, 0);
        for (char c : t) {
            ++cnt[c - 'a'];
        }
        int res = 0;
        vector<int> cur0(26, 0);
        for (int i = 0; i < m; ++i) {
            cur0[t[i] - 'a'] += cnt0;
            for (int j = 0; j < 26; ++j) {
                if (cur0[j] > cnt[j]) {
                    goto end;
                }
            }
            int k1 = (i + 1);
            int len0 = k1 * cnt0;
            int len1 = m - len0;
            if (len0 >= m) {
                goto end;
            } else if (len1 % cnt1 != 0) {
                continue;
            }
            int k2 = len1 / cnt1;
            int startr1 = ind1 * k1;
            int h1 = val(0, k1, F, powb), h2 = val(startr1, k2, F, powb);
            if (k1 == k2 && h1 == h2) {
                continue;
            }
            bool ok = true;
            for (int a = 0, b = 0; ok && a < n; ++a) {
                if (s[a] == '0') {
                    int h = val(b, k1, F, powb);
                    if (h != h1) ok = false;
                    b += k1;
                } else {
                    int h = val(b, k2, F, powb);
                    if (h != h2) ok = false;
                    b += k2;
                }
            }
            res += ok;
        }
        end:;
        out << res << "\n";
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
