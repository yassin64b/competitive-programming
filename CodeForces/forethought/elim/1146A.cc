#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    string s;
    cin >> s;
    int n = s.size(), c = count(begin(s), end(s), 'a');
    cout << min(n, 2 * c - 1) << "\n";

    return 0;
}