#include <bits/stdc++.h>

using namespace std;


int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int> fi(n + 1, -1), la(n + 1, -1);
        for (int i = 0; i < n; ++i) {
            if (fi[a[i]] == -1) fi[a[i]] = i;
        }
        for (int i = n - 1; i >= 0; --i) {
            if (la[a[i]] == -1) la[a[i]] = i;
        }
        int num_dis = 0;
        for (int i = 1; i <= n; ++i) 
            num_dis += la[i] != -1;
        int mx = 0;
        for (int i = 1; i <= n; ) {
            int j = i, upto = -1, cnt = 0;
            while (j <= n && (fi[j] == -1 || fi[j] > upto)) {
                if (fi[j] != -1) {
                    upto = la[j];
                    ++cnt;
                }
                ++j;
            }
            mx = max(mx, cnt);
            i = j;
        }
        cout << num_dis - mx << "\n";
        
    }
    return 0;
}