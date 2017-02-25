#include <iostream>
#include <vector>

using namespace std;

using vpii = vector<pair<long long, long long>>;
using vvpii = vector<vpii>;

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        int N, M;
        cin >> N >> M;

        long long res = 0;
        vvpii dp(N+1, vpii(M+1, make_pair(0, 0))), next;
        dp[0][0] = make_pair(1, 1);
        for (int r = 1; r <= N+M; ++r) {
            res += dp[N][M].first + dp[N][M].second;
            next.assign(N+1, vpii(M+1, make_pair(0, 0)));
            for (int i = 0; i <= N; ++i) {
                for (int j = 0; j <= M; ++j) {
                    for (int len = 1; i+len <= N; ++len) {
                        next[i+len][j].first += dp[i][j].second;
                    }
                    for (int len = 1; j+len <= M && j+len < i; ++len) {
                        next[i][j+len].second += dp[i][j].first;
                    }
                }
            }
            dp = next;
        }
        res += dp[N][M].first + dp[N][M].second;

        long long all = 1;
        for (int i = M+N; i >= 1; --i) {
            all *= i;
        }
        long long nfac = 1, mfac = 1;
        for (int i = N; i >= 1; --i) nfac *= i;
        for (int i = M; i >= 1; --i) mfac *= i;
        all /= nfac;
        all /= mfac;
        cout.precision(17);
        //cout << N << " " << M << "\n";
        //cout << res << " / " << all << "\n";
        cout << "Case #" << t << ": " << fixed << (double)res / all << endl;
    }
}