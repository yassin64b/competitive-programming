#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int N;
    cin >> N;
    i64 res = 1LL * N * (N - 1) / 2;
    cout << res << "\n";

    return 0;
}