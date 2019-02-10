#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int x, y, z, a, b, c;
    cin >> x >> y >> z >> a >> b >> c;

    if (a >= x && a + b >= x + y && a + b + c >= x + y + z) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }


    return 0;
}