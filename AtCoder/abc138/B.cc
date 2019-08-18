#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int N;
    cin >> N;
    double inv_sum = 0;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        inv_sum += 1. / a;
    }
    cout.precision(17);
    cout << fixed << 1. / inv_sum << "\n";
    
    return 0;
}