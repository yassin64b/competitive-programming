#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << ((i + j) % 2 == 0 ? "W" : "B");
        }
        cout << "\n";
    }

    return 0;
}