#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }   
    string s;
    cin >> s;
    
    long long res = 0;
    for (int i = 0; i < n; ++i) {
        int j = i;
        while (j + 1 < n && s[j + 1] == s[i]) {
            ++j;
        }
        int len = j - i + 1;
        if (len > k) {
            vector<int> tmp;
            for (int x = i; x <= j; ++x) {
                tmp.push_back(a[x]);
            }
            sort(begin(tmp), end(tmp));
            reverse(begin(tmp), end(tmp));
            res += accumulate(begin(tmp), begin(tmp) + k, 0LL);
        } else {
            for (int x = i; x <= j; ++x) {
                res += a[x];
            }
        }
        i = j;
    }
    cout << res << "\n";



    return 0;
}