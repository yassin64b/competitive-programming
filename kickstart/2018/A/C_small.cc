#include <bits/stdc++.h>

using namespace std;

class kickstart_scrambled_words {
public:
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        for (int t = 1; t <= T; ++t) {
            int L;
            in >> L;
            vector<string> dict(L);
            for (int i = 0; i < L; ++i) {
                in >> dict[i];
            }
            char s1, s2;
            int N, A, B, C, D;
            in >> s1 >> s2 >> N >> A >> B >> C >> D;
            string s = ""s + s1 + s2;
            int x_1 = s2, x_2 = s1;
            for (int i = 2; i < N; ++i) {
                int x = (1LL * A * x_1 + 1LL * B * x_2 + C) % D;
                s += x % 26 + 'a';
                x_2 = x_1;
                x_1 = x;
            }
            int res = 0;
            for (int i = 0; i < L; ++i) {
                int len = dict[i].size();
                const string &cur = dict[i];
                vector<int> cnt1(26, 0);
                for (char c : cur) ++cnt1[c - 'a'];
                for (int j = 0; j + len <= N; ++j) {
                    if (s[j] == cur[0] && s[j + len - 1] == cur[len - 1])
                    {
                        vector<int> cnt2(26, 0);
                        for (int k = j; k < j + len; ++k) ++cnt2[s[k] - 'a'];
                        if (cnt1 == cnt2) {
                            ++res;
                            break;
                        }
                    }
                }
            }
            out << "Case #" << t << ": " << res << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    kickstart_scrambled_words solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
