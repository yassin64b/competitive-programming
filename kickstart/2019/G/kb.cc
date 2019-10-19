#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int N;
        i64 M;
        cin >> N >> M;
        vector<i64> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        i64 k = 0;
        for (int i = 50; i >= 0; --i) {
            int cnt_set = 0;
            for (int j = 0; j < N; ++j) {
                if ((A[j] & (1LL << i)))
                    ++cnt_set;
            }
            if (2 * cnt_set >= N) {
                k |= (1LL << i);
            }
        }
        i64 cur_sum = 0;
        for (int i = 0; i < N; ++i) {
            cur_sum += (A[i] ^ k);
        }
        if (cur_sum > M) {
            cout << "Case #" << t << ": " << -1 << "\n";
            continue;
        }
        for (int i = 50; i >= 0; --i) {
            if (!(k & (1LL << i))) {
                i64 tk = (k | (1LL << i));
                i64 new_sum = 0;
                for (int j = 0; j < N; ++j) {
                    new_sum += (A[j] ^ tk);
                }
                if (new_sum <= M) {
                    k = tk;
                }
            }
        }
        cout << "Case #" << t << ": " << k << "\n";
    }
    return 0;
}