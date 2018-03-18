#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 1'000'000'007;
constexpr int base = 33;

class kickstart_scrambled_words {
public:
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        vector<int> base_pow(100'001, 1);
        for (int i = 1; i <= 100'000; ++i) {
            base_pow[i] = (1LL * base_pow[i - 1] * base) % MOD;
        }
        for (int t = 1; t <= T; ++t) {
            int L;
            in >> L;
            vector<string> dict(L);
            map<int, int> hashes[26][26]{};
            set<int> lens;
            for (int i = 0; i < L; ++i) {
                in >> dict[i];
                lens.insert(dict[i].size());
                int cnt[26]{};
                for (char c : dict[i]) ++cnt[c - 'a'];
                int hash = 0;
                for (int j = 25; j >= 0; --j) {
                    hash = (1LL * hash * base + cnt[j] + 1) % MOD;
                }
                ++hashes[dict[i][0] - 'a'][dict[i].back() - 'a'][hash];
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
            for (int len : lens) {
                if (len > N) continue;

                int hash = 0;
                for (int j = 0; j < len - 1; ++j)
                    hash += base_pow[s[j] - 'a'], hash %= MOD;
                for (int j = 0; j < 26; ++j)
                    hash += base_pow[j], hash %= MOD;

                for (int j = 0; j + len <= N; ++j) {
                    hash += base_pow[s[j + len - 1] - 'a'];
                    if (j > 0) hash -= base_pow[s[j - 1] - 'a'];
                    hash = (hash % MOD + MOD) % MOD;
                    if (hashes[s[j] - 'a'][s[j + len - 1] - 'a'].count(hash)) {
                        res += hashes[s[j] - 'a'][s[j + len - 1] - 'a'][hash];
                        hashes[s[j] - 'a'][s[j + len - 1] - 'a'][hash] = 0;
                    }
                }
            }
            /*for (int i = 0; i < L; ++i) { // too slow
                int len = dict[i].size();
                const string &cur = dict[i];
                vector<int> cnt1(26, 0);
                vector<int> cnt2(26, 0);
                for (char c : cur) ++cnt1[c - 'a'];
                for (int j = 0; j < len - 1 && j < N; ++j) 
                    ++cnt2[s[j] - 'a'];
                for (int j = 0; j + len <= N; ++j) {
                    ++cnt2[s[j + len - 1] - 'a'];
                    if (j > 0) --cnt2[s[j - 1] - 'a'];
                    if (s[j] == cur[0] && s[j + len - 1] == cur[len - 1]
                        && cnt1 == cnt2)
                    {
                        ++res;
                        break;
                    }
                }
            }*/
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
