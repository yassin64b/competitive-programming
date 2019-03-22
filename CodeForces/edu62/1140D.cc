#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    int w = 0;
    for (int i = 2; i <= n - 1; ++i) {
        w += 1 * i * (i + 1);
    }
    cout << w << "\n";
    
    return 0;
}