#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int P, Q, R;
    cin >> P >> Q >> R;
    cout << min(P + Q, min(Q + R, R + P)) << "\n";
    
    return 0;
}