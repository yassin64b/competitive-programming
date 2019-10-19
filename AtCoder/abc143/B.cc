#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> d(N);
    for (int i = 0; i < N; ++i) {
        cin >> d[i];
    }
    int res = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            res += d[i] * d[j];
        }
    }
    cout << res << "\n";
    
    return 0;
}