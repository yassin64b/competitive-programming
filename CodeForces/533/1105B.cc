#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int x = 0;
    for (char c = 'a'; c <= 'z'; ++c) {
        int cur_x = 0;
        for (int i = 0, cur_cnt = 0; i < n; ++i) {
            if (s[i] == c) {
                ++cur_cnt;
                if (cur_cnt == k) {
                    ++cur_x;
                    cur_cnt = 0;
                }
            } else {
                cur_cnt = 0;
            }
        }
        x = max(x, cur_x);
    }
    cout << x << "\n";
    
    
    return 0;
}