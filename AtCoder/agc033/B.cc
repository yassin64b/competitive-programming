#include <bits/stdc++.h>

using namespace std;

bool check_dim(int D, int L, int R, const string &T, const string &S, int s) {
    const int N = T.size();
    // keep current winning interval for aoki
    int x = 1, y = D;
    // process moves in reverse
    for (int i = N - 1; x <= y && i >= 0; --i) {
        if (T[i] == L) { // aoki can make the interval larger
            y = min(D, y + 1);
        } else if (T[i] == R) {
            x = max(1, x - 1);
        }
        if (S[i] == L) { // takashi can make it smaller
            ++x;
        } else if (S[i] == R) {
            --y;
        }
    }
    // starting point must be in the interval
    return x <= s && s <= y;
}

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int H, W, N, sr, sc;
    cin >> H >> W >> N >> sr >> sc;
    string S, T;
    cin >> S >> T;

    constexpr int L = 0, R = 1, U = 2, D = 3;
    map<char, int> m{{'L', L}, {'R', R}, {'U', U}, {'D', D}};
    for (int i = 0; i < N; ++i) {
        S[i] = m[S[i]];
        T[i] = m[T[i]];
    }
    
    if (!check_dim(W, L, R, T, S, sc)
        || !check_dim(H, U, D, T, S, sr)) {
        cout << "NO\n";
        return 0;
    }    
    cout << "YES\n";

    return 0;
}