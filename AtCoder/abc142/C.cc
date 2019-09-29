#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> B(N + 1);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        B[A[i]] = i + 1;
    }
    for (int i = 1; i <= N; ++i) {
        cout << B[i] << " ";
    }
    cout << "\n";
    
    return 0;
}