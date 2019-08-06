#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }
    --H[0];
    for (int i = 1; i < N; ++i) {
        if (H[i] - 1 >= H[i - 1]) {
            --H[i];
        } else if (H[i] < H[i - 1]) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    
    return 0;
}