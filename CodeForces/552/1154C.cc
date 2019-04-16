#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int a, b, c;
    cin >> a >> b >> c;
    int mx_days = 0;
    for (int i = 0; i < 7; ++i) {
        int ca = a, cb = b, cc = c;
        int days = 0;
        for (int j = i; j < 7 && ca >= 0 && cb >= 0 && cc >= 0; ++j) {
            ca -= (j % 7 == 0 || j % 7 == 3 || j % 7 == 6);
            cb -= (j % 7 == 1 || j % 7 == 5);
            cc -= (j % 7 == 2 || j % 7 == 4);
            ++days;
        }
        int cnt = max(0, min(ca / 3, min(cb / 2, cc / 2)));
        ca -= cnt * 3;
        cb -= cnt * 2;
        cc -= cnt * 2;
        days += cnt * 7;
        for (int j = 0; j < 7 && ca >= 0 && cb >= 0 && cc >= 0; ++j) {
            ca -= (j % 7 == 0 || j % 7 == 3 || j % 7 == 6);
            cb -= (j % 7 == 1 || j % 7 == 5);
            cc -= (j % 7 == 2 || j % 7 == 4);
            ++days;
        }
        days -= (ca < 0 || cb < 0 || cc < 0);
        mx_days = max(mx_days, days);
    }
    cout << mx_days << endl;
    
    return 0;
}