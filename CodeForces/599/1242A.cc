#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    long long n;
    cin >> n;
    if (n == 1) {
        cout << 1 << "\n";
        return 0;
    }
    vector<long long> divs;
    for (long long i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            divs.emplace_back(i);
            while (n % i == 0)
                n /= i;
        }
    }
    if (n > 1) 
        divs.emplace_back(n);
    if (divs.size() > 1U) {
        cout << 1 << "\n";
    } else {
        long long x = divs[0];
        cout << x << "\n";
    }
    

    return 0;
}