#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int N;
    string S;
    cin >> N >> S;
    int res = 1;
    for (int i = 1; i < N; ++i) {
        res += S[i] != S[i - 1];
    }
    cout << res << "\n";
    
    return 0;
}