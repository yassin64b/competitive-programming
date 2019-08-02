#include <bits/stdc++.h>

using namespace std;

bool is_prime(long long x) {
    if (x <= 2) return (x == 2);
    if (x % 2 == 0) return false;
    for (long long i = 3; i * i <= x; i += 2) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n;
    cin >> n;
    int m = n;
    while (!is_prime(m)) ++m; // m <= 3 * n / 2
    cout << m << "\n";
    for (int i = 0; i < n; ++i) {
        cout << i + 1 << " " << (i + 1) % n + 1 << "\n"; 
    }
    for (int i = 0; i < m - n; ++i) {
        cout << i + 1 << " " << i + 1 + n / 2 << "\n";
    }

    return 0;
}