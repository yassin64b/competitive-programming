#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void brute(int i, int N, int &cnt, i64 cur1, i64 cur2, 
           const vector<int> &A, const vector<int> &B, int H) {
    if (i >= N) {
        cnt += (cur1 >= H) && (cur2 >= H);
        return;
    }
    brute(i + 1, N, cnt, cur1 + A[i], cur2, A, B, H);
    brute(i + 1, N, cnt, cur1, cur2 + B[i], A, B, H);
    brute(i + 1, N, cnt, cur1 + A[i], cur2 + B[i], A, B, H);
}
int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int N, H;
        cin >> N >> H;
        vector<int> A(N), B(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        for (int i = 0; i < N; ++i) {
            cin >> B[i];
        }
        int cnt = 0;
        brute(0, N, cnt, 0, 0, A, B, H);
        cout << "Case #" << t << ": " << cnt << "\n";
    }
    return 0;
}