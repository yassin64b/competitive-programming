#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int A, B;
    cin >> A >> B;
    
    if ((A - B) % 2 == 0) {
        cout << abs(A - (A - B) / 2) << "\n";
    } else {
        cout << "IMPOSSIBLE\n";
    }

    return 0;
}