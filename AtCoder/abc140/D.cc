#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int N, K;
    string S;
    cin >> N >> K >> S;
    string T;
    T += S[0];
    for (int i = 1; i < N; ++i) {
        if (S[i] != S[i - 1]) {
            T += S[i];
        }
    }
    int res = 0;
    for (int i = 0; i < N; ++i) {
        res += (i > 0 && S[i] == 'L' && S[i - 1] == 'L');
        res += (i < N - 1 && S[i] == 'R' && S[i + 1] == 'R');
    }
    int m = T.size();
    int cnt = (m - 1) / 2;
    cnt = min(cnt, K);
    K -= cnt;
    res += cnt * 2;

    if (K > 0) {
        res = N - 1;
    }

    cout << res << "\n";

    return 0;
}