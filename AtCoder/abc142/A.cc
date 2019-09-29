#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int N;
    cin >> N;
    int num_odd = (N + 1) / 2;
    cout.precision(17);
    cout << fixed << (double)num_odd / N << "\n";
    return 0;
}