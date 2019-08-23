#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    cout << "?";
    for (int i = 0; i < 100; ++i) {
        cout << " " << (i);;
    }
    cout << "\n";
    cout.flush();
    int ax;
    cin >> ax;
    if (ax == -1) return 0;

    cout << "?";
    for (int i = 1; i <= 100; ++i) {
        cout << " " << (i << 7);;
    }
    cout << "\n";
    cout.flush();
    int bx;
    cin >> bx;
    if (bx == -1) return 0;

    int mask1 = (1 << 7) - 1;
    int mask2 = (1 << 14) - 1;
    int mask3 = (mask2 & (~mask1));
    int ans = (bx & mask1) | (ax & mask3);

    cout << "! " << (ans & ((1 << 14) - 1)) << "\n";
    cout.flush();

    return 0;
}