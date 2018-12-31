#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int y, b, r;
    cin >> y >> b >> r;

    y = min(y, min(b - 1, r - 2));

    cout << y + y + 1 + y + 2 << "\n";

    return 0;
}