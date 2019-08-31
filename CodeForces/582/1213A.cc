#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n;
    cin >> n;
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        cnt0 += (x % 2 == 0);
        cnt1 += (x % 2);
    }
    cout << min(cnt0, cnt1) << "\n";

    return 0;
}