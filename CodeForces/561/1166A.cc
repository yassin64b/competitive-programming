#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> cnt(26, 0);
    for (int i = 0; i < n; ++i) {
        string name;
        cin >> name;
        ++cnt[name[0] - 'a'];
    }
    int min_x = 0;
    for (int i = 0; i < 26; ++i) {
        int cnt1 = cnt[i] / 2, cnt2 = cnt[i] - cnt1;
        min_x += cnt1 * (cnt1 - 1) / 2 + cnt2 * (cnt2 - 1) / 2;
    }
    cout << min_x << "\n";
    
    return 0;
}