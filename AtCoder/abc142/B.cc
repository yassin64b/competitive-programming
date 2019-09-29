#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    int res = 0;
    for (int i = 0; i < N; ++i) {
        int h;
        cin >> h;
        res += (h >= K);
    }
    cout << res << "\n";
    
    return 0;
}