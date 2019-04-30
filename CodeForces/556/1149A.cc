#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> a(n);
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        cnt1 += (a[i] == 1);
        cnt2 += (a[i] == 2);
    }
    if (cnt1 == 0 || cnt2 == 0) {
        for (int i = 0; i < n; ++i) cout << a[i] << " ";
        cout << "\n";
    } else {
        cout << 2 << " " << 1 << " ";
        --cnt1;
        --cnt2;
        for (int i = 2; i < n; ++i) {
            if (cnt2 > 0) {
                --cnt2;
                cout << 2 << " ";
            } else {
                --cnt1;
                cout << 1 << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}