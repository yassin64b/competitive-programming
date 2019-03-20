#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n, v;
    cin >> n >> v;
    int cost = min(n - 1, v);
    for (int i = 2; i <= n - v; ++i) {
        cost += i;
    }
    cout << cost << "\n";

    return 0;
}