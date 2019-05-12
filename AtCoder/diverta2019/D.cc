#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    i64 N;
    cin >> N;
    i64 sum = 0;
    for (int x = 1; (i64)x * x <= N && x < N - x; ++x) {
        if ((N - x) % x == 0) {
            i64 m = (N - x) / x;
            sum += m * (N / m == N % m);
        }
    }
    cout << sum << "\n";

    return 0;
}