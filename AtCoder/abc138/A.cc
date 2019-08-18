#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int a;
    string s;
    cin >> a >> s;
    if (a >= 3200) cout << s << "\n";
    else cout << "red\n";
    
    return 0;
}