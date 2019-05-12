#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (a % 2 == 0) ++cnt0;
        else ++cnt1;
    } 
    int res = 0;
    for (int i = 0; i < m; ++i) {
        int b;
        cin >> b;
        if (b % 2 == 0 && cnt1) --cnt1, ++res;
        if (b % 2 == 1 && cnt0) --cnt0, ++res;
    }
    cout << res << "\n";
    
    return 0;
}