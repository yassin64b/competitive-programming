#include <bits/stdc++.h>

using namespace std;

int num_dig(int x) {
    int res = 0;
    while (x) {
        ++res;
        x /= 10;
    }
    return res;
}

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int N;
    cin >> N;
    int res = 0;
    for (int i = 1; i <= N; ++i) {
        res += (num_dig(i) % 2);
    }
    cout << res << "\n";

    return 0;
}