#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    string op;
    cin >> op;
    int cur = 0, mn = 0;
    for (char c : op) {
        cur += (c == '+') - (c == '-');
        mn = min(mn, cur);
    }
    cout << cur - mn << "\n";
    
    return 0;
}