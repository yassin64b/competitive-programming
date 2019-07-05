#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int N;
    i64 K;
    cin >> N >> K;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    i64 cur_sum = 0, res = 0;
    for (int i = 0, j = 0; i < N; ++i) {
        while (j < N && cur_sum + a[j] < K) {
            cur_sum += a[j];
            ++j;
        }
        res += N - j;
        cur_sum -= a[i];
    }
    cout << res << "\n";

    return 0;
}