#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> W(N);
    for (int i = 0; i < N; ++i) {
        cin >> W[i];
    }
    int sum = accumulate(begin(W), end(W), 0);
    int cur = 0, res = 1000000;
    for (int i = 0; i < N - 1; ++i) {
        cur += W[i];
        sum -= W[i];
        res = min(res, abs(cur - sum));
    }
    cout << res << "\n";
    
    return 0;
}