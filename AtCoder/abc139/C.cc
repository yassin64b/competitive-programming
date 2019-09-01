#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }
    int mx = 1, cur = 1;
    for (int i = 1; i < N; ++i) {
        if (H[i] <= H[i - 1]) {
            ++cur;
            mx = max(mx, cur);
        } else {
            cur = 1;
        }
    }
    cout << mx - 1 << "\n";

    return 0;
}