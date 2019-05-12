#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int R, G, B, N;
    cin >> R >> G >> B >> N;
    int res = 0;
    for (int r = 0; r * R <= N; ++r) {
        for (int g = 0; r * R + g * G <= N; ++g) {
            int need = N - r * R - g * G;
            if (need % B == 0) {
                ++res;
            }
        }
    }
    cout << res << "\n";

    return 0;
}