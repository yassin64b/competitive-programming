#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> L(N);
    constexpr int MX = 1'001;
    vector<int> pre(MX + 1);
    for (int i = 0; i < N; ++i) {
        cin >> L[i];
        ++pre[L[i]];
    }
    for (int i = 1; i <= MX; ++i) {
        pre[i] += pre[i - 1];
    }
    long long res = 0;
    sort(begin(L), end(L));
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1, k = i + 2; j < N; ++j) {
            while (k < N && L[k] < L[i] + L[j]) {
                ++k;
            }
            res += k - j - 1;
        }
    }
    cout << res << "\n";


    return 0;
}