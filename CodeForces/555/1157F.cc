#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    constexpr int MXV = 200'001;
    vector<int> cnt(MXV, 0);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++cnt[a[i]];
    }
    int mx_len = 0, start = -1, end = -1;
    for (int i = 0; i < MXV; ) {
        int len = 0;
        int j = i;
        if (cnt[j] == 1) {
            ++len;
            ++j;
        }
        while (j < MXV && cnt[j] > 1) {
            len += cnt[j];
            ++j;
        }
        if (j < MXV && cnt[j] == 1) {
            ++len;
            ++j;
        }
        if (len > mx_len) {
            mx_len = len;
            start = i;
            end = j - 1;
        }
        if (i >= j - 1) {
            ++i;
        } else {
            i = j - 1;
        }
    }
    cout << mx_len << "\n";
    cout << start << " ";
    for (int i = start; i <= end; ++i) {
        for (int j = 0; j < cnt[i] - 1; ++j) {
            cout << i << " ";
        }
    }
    for (int i = end; i > start; --i) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}