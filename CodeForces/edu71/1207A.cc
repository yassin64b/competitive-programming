#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int b, p, f, h, c;
        cin >> b >> p >> f >> h >> c;
        int mx = 0;
        if (h < c) {
            swap(p, f);
            swap(h, c);
        }
        while (p > 0 && b > 1) {
            mx += h;
            --p;
            b -= 2;
        }
        while (f > 0 && b > 1) {
            mx += c;
            --f;
            b -= 2;
        }
        cout << mx << "\n";
    }
    return 0;
}