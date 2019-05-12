#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    string res;
    int m = (n - k) / 2;
    while ((int)res.size() < n) {
        res += string(m, '0') + "1";
    }
    cout << res.substr(0, n) << endl;

    return 0;
}