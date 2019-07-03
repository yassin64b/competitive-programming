#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    string S;
    cin >> S;
    for (int i = 0; i + 1 < 4; ++i) {
        if (S[i] == S[i + 1]) {
            cout << "Bad\n";
            return 0;
        }
    }
    cout << "Good\n";
    return 0;
}