#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int N;
    string A, B, C;
    cin >> N >> A >> B >> C;

    int res = 0;
    for (int i = 0; i < N; ++i) {
        if (A[i] == B[i] && B[i] == C[i]) {
            res += 0;
        } else if (A[i] == B[i] || B[i] == C[i] || A[i] == C[i]) {
            res += 1;
        } else {
            res += 2;
        }
    }
    cout << res << "\n";

    return 0;
}