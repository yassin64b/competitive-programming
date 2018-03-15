#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 1000000007;

class apac_c {
public:
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        for (int t = 1; t <= T; ++t) {
            int V, S;
            in >> V >> S;
            vector<string> vocab(V);
            for (int i = 0; i < V; ++i) {
                in >> vocab[i];
            }
            out << "Case #" << t << ": ";
            for (int s = 0; s < S; ++s) {
                string cipher;
                in >> cipher;
                int n = cipher.size();
                vector<int> dp(n + 1, 0);
                dp[0] = 1;
                for (int i = 0; i < n; ++i) {
                    for (const string &voc : vocab) {
                        if (i + (int)voc.size() <= n) {
                            int cnt[26]{};
                            for (char c : voc) ++cnt[c - 'a'];
                            for (int j = i; j < i + (int)voc.size(); ++j) --cnt[cipher[j] - 'a'];
                            bool ok = true;
                            for (int j = 0; j < 26; ++j) if (cnt[j]) ok = false;
                            if (!ok) continue;
                            dp[i + (int)voc.size()] += dp[i];
                            dp[i + (int)voc.size()] %= MOD;
                        }
                    }
                }
                out << dp[n] << " ";
            }
            out << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    apac_c solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
