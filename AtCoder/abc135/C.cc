#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> A(N + 1), B(N);
    for (int i = 0; i < N + 1; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> B[i];
    }
    long long res = 0;
    for (int i = 0; i < N; ++i) {
        int cntl = min(A[i], B[i]);
        res += cntl;
        A[i] -= cntl;
        B[i] -= cntl;
        int cntr = min(A[i + 1], B[i]);
        res += cntr;
        A[i + 1] -= cntr;
        B[i] -= cntr;
    }
    cout << res << "\n";

    return 0;
}