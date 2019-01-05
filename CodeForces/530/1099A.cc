#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int w, h, u1, d1, u2, d2;
    cin >> w >> h >> u1 >> d1 >> u2 >> d2;

    for (int i = h; i >= 0; --i) {
        w += i;
        if (i == d1) {
            w -= u1;
        } else if (i == d2) {
            w -= u2;
        }
        w = max(w, 0);
    }
    cout << w << "\n";

    return 0;
}