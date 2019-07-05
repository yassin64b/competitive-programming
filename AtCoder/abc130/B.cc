#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int N, X;
    cin >> N >> X;
    int cnt = 1;
    for (int i = 0, cur = 0; i < N; ++i) {
        int L;
        cin >> L;
        cur += L;
        cnt += (cur <= X);
    }
    cout << cnt << "\n";

    return 0;
}