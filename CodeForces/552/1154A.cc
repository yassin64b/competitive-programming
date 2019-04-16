#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int x1, x2, x3, x4;
    cin >> x1 >> x2 >> x3 >> x4;
    int mx = max(x1, max(x2, max(x3, x4)));
    if (mx == x1) swap(x1, x4);
    if (mx == x2) swap(x2, x4);
    if (mx == x3) swap(x3, x4);
    cout << mx - x1 << " " << mx - x2 << " " << mx - x3 << endl;
    
    return 0;
}