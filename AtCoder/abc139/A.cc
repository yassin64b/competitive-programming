#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    string S, T;
    cin >> S >> T;
    int res = 0;
    for (int i = 0; i < 3; ++i) {
        res += S[i] == T[i];
    }
    cout << res << "\n";
    
    return 0;
}