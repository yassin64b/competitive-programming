#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    string S;
    int K;
    cin >> S >> K;
    const int n = S.size();
    if (set<char>(begin(S), end(S)).size() == 1U) {
        cout << (1LL * n * K) / 2 << "\n";
        return 0;
    }
    int cnt1 = 0;
    bool change_last = false;
    for (int i = 1; i < n; ++i) {
        if (S[i] == S[i - 1]) {
            ++cnt1;
            if (i == n - 1) {
                change_last = true;
            }
            ++i;
        }
    }
    int add = 0;
    if (!change_last && S.back() == S[0]) {
        int cnt2 = 1;
        for (int i = 2; i < n; ++i) {
            if (S[i] == S[i - 1]) {
                ++cnt2;
                ++i;
            }
        }
        if (cnt2 > cnt1) {
            add = K - 1;
        }
    }
    cout << 1LL * K * cnt1 + add << "\n";

    return 0;
}