#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int Q;
    cin >> Q;
    for (int q = 0; q < Q; ++q) {
        i64 k;
        int x;
        cin >> k >> x;
        cout << (k - 1) * 9 + x << "\n";
    }   
    return 0;
}