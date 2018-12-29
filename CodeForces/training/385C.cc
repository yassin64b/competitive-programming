#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    constexpr int MXV = 10'000'000;

    int n;
    cin >> n;
    vector<int> x(n), cnt(MXV + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
        ++cnt[x[i]];
    }

    vector<int> prime(MXV + 1, 1);
    vector<long long> f(MXV + 1, 0);
    prime[0] = prime[1] = 0;
    for (int i = 2; i <= MXV; ++i) {
        if (prime[i]) {
            f[i] = cnt[i];
            for (int j = 2 * i; j <= MXV; j += i) {
                prime[j] = 0;
                f[i] += cnt[j];
            }
        }
    }

    for (int i = 1; i <= MXV; ++i) {
        f[i] += f[i - 1];
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        cout << f[min(r, MXV)] - f[min(l - 1, MXV)] << "\n";
    }

    return 0;
}