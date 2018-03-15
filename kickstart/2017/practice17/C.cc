#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        int L, R;
        cin >> L >> R;

        int num = min(L, R);
        
        cout << "Case #" << t << ": " << num * (long long)(num + 1) / 2 << "\n";
    }
}