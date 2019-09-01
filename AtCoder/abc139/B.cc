#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int A, B;
    cin >> A >> B;
    int cur = 1, res = 0;
    while (cur < B) {
        cur += A - 1;
        ++res;
    }
    cout << res << "\n";

    return 0;
}