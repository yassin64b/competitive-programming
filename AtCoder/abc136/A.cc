#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int A, B, C;
    cin >> A >> B >> C;
    int transfer = min(C, A - B);
    cout << C - transfer << "\n";

    return 0;
}