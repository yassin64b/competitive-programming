#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<long long> f;
    vector<int> div;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            div.push_back(i);
            if (i != n / i) {
                div.push_back(n / i);
            }
        }
    }
    for (int k : div) {
        f.push_back(1LL * n * (n - k + 2) / (2 * k));
    }
    sort(begin(f), end(f));
    for (long long x : f) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}