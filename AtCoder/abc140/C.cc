#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> B(N - 1);
    for (int i = 0; i < N - 1; ++i) {
        cin >> B[i];
    }
    int mx_sum = 0;
    for (int i = 0; i < N; ++i) {
        int cur = 100'000;
        if (i < N - 1) {
            cur = min(cur, B[i]);
        }
        if (i - 1 >= 0) {
            cur = min(cur, B[i - 1]);
        }
        mx_sum += cur;
    }
    cout << mx_sum << "\n";

    return 0;
}