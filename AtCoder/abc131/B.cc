#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int N, L;
    cin >> N >> L;
    int bst_dist = 10000, sum = 0;
    for (int i = 1; i <= N; ++i) {
        int cur = L + i - 1;
        sum += cur;
        if (abs(cur) < abs(bst_dist)) {
            bst_dist = cur;
        }
    }
    cout << sum - bst_dist << "\n";

    return 0;
}