#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    string c_tab;
    cin >> c_tab;
    for (int i = 0; i < 5; ++i) {
        string c_hand;
        cin >> c_hand;
        if (c_hand[0] == c_tab[0] || c_hand[1] == c_tab[1]) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";

    return 0;
}