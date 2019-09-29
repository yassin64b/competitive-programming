#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int N, S;
        cin >> N >> S;
        vector<int> C(N);
        vector<vector<int>> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> C[i];
            A[i].resize(C[i]);
            for (int j = 0; j < C[i]; ++j) {
                cin >> A[i][j];
            }
            sort(begin(A[i]), end(A[i]));
        }

        map<vector<int>, int> cnt_dom;
        for (int i = 0; i < N; ++i) {
            for (int mask = 0; mask < (1 << C[i]); ++mask) {
                vector<int> subset;
                for (int j = 0; j < C[i]; ++j) {
                    if (mask & (1 << j)) {
                        subset.push_back(A[i][j]);
                    }
                }
                ++cnt_dom[subset];
            }
        }
        long long cnt = 0;
        for (int i = 0; i < N; ++i) {
            cnt += N - cnt_dom[A[i]];
        }
        cout << "Case #" << t << ": " << cnt << "\n";
    }
    return 0;
}