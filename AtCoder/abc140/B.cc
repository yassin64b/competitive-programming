#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    vector<int> B(N);
    for (int i = 0; i < N; ++i) {
        cin >> B[i];
    }
    vector<int> C(N - 1);
    for (int i = 0; i < N - 1; ++i) {
        cin >> C[i];
    }
    int res = 0;
    for (int i = 0; i < N; ++i) {
        res += B[A[i] - 1];
        if (i > 0 && A[i] == A[i - 1] + 1) {
            res += C[A[i - 1] - 1];
        }
    }
    cout << res << "\n";

    return 0;
}