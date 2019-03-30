#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int N;
    string s;
    cin >> N >> s;
    cout << (count(begin(s), end(s), 'R') > count(begin(s), end(s), 'B') ? "Yes" : "No") << "\n";
    return 0;
}