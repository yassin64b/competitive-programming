#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    double H, L;
    cin >> H >> L;
    cout.precision(17);
    cout << fixed << (L * L - H * H) / (2 * H) << "\n";

    return 0;
}