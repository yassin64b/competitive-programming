#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int W, H, x, y;
    cin >> W >> H >> x >> y;

    double area = (double)W * H;
    cout.precision(17);
    cout << fixed << area / 2. << " " << (x == W / 2. && y == H / 2.) << "\n";

    return 0;
}