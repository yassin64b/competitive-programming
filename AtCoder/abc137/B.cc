#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int K, X;
    cin >> K >> X;
    for (int i = X - K + 1; i < X + K; ++i) {
        cout << i << " ";
    }
    cout << "\n";

    return 0;
}